/*
 * filename: process-injection-exmpl-v1.c
 * from: Malware Development: Process Injection
 *       https://www.youtube.com/watch?v=A6EKDAKBXPs
 * v1: NOT actually write to virtual memory yet (in v2)
 * last: 20250908 (en)
 */
#include <stdio.h>
#include <windows.h>

const char *k = "[+]";
const char *i = "[+]";
const char *e = "[-]";

DWORD PID = 0;                    /* for OpenProcess() function */
HANDLE hProcess, hThread = NULL;  /* for OpenProcess() function */
LPVOID rBuffer = NULL;            /* for VirtualAllocEx() function */

unsigned char injected[] = "\x41\x41\x41\x41\x41\x41\x41\x4\x41"; /* unsigned char *crowPuke[] = ... */


/* main */
int main(int argc, char **argv) {

	if (argc < 2) {
		printf("%s usage: %s <PID>\n", e, argv[0]);
		return EXIT_FAILURE;
	}

	PID = atoi(argv[1]);
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

	return EXIT_SUCCESS;
}

