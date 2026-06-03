/*
 * filename: get-process-id-win.c
 * from: https://cocomelonc.github.io/pentest/2021/09/29/findmyprocess.html
 * last: 20250909 (en) -- v2
*/
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tlhelp32.h>

// find process ID by process name
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

int main(int argc, char *argv[]) {
	int pid = 0; // process ID

	pid = get_process_id_by_name(argv[1]);
	if (pid) {
		printf("PID = %d\n", pid);
	}
	return 0;
}

