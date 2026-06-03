/*
 * filename: create-process-exmpl.c
 * last: 20250909 (v2)
 */
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <wchar.h> /* v2 */

int main(int argc, char **argv) {

	/* [**1] */
	STARTUPINFOW si = {0};
	PROCESS_INFORMATION pi = {0};

	/* original from:
	 * https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw
	BOOL CreateProcessW(
		[in, optional]      LPCWSTR               lpApplicationName,
		[in, out, optional] LPWSTR                lpCommandLine,
		[in, optional]      LPSECURITY_ATTRIBUTES lpProcessAttributes,
		[in, optional]      LPSECURITY_ATTRIBUTES lpThreadAttributes,
		[in]                BOOL                  bInheritHandles,
		[in]                DWORD                 dwCreationFlags,
		[in, optional]      LPVOID                lpEnvironment,
		[in, optional]      LPCWSTR               lpCurrentDirectory,
		[in]                LPSTARTUPINFOW        lpStartupInfo,
		[out]               LPPROCESS_INFORMATION lpProcessInformation
	);
	*/
	wchar_t path[] = L"c:\\Windows\\System32\\notepad.exe"; /* v2 */
	if(!CreateProcessW(
		/* L"c:\\Windows\\System32\\notepad.exe", */
		path,                                               /* v2 */
		NULL,
		NULL,
		NULL,
		FALSE,
		BELOW_NORMAL_PRIORITY_CLASS,
		NULL,
		NULL,
		/* [**1]
		 * from: https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasuserw
		 * [in] lpStartupInfo: A pointer to a STARTUPINFO or STARTUPINFOEX structure ...
		 * [out] lpProcessInformation: A pointer to a PROCESS_INFORMATION structure ...
		 */
		&si,
		&pi)) {
		printf("(-) failed to create process, error: %ul", GetLastError());
		return EXIT_FAILURE;
	}

	/* printf("(+) process started! pid: %ul\n", pi.dwProcessId); */
	printf("(+) staring process: \"%ls\" with pid: %ul\n", path, pi.dwProcessId); /* v2 */


	return EXIT_SUCCESS;
}

