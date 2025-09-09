/*
 * filename: message-box-exmpl.c
 * last: 20250908
 */
#include <stdio.h>
#include <string.h>
#include <windows.h>


int main(int argc, char **argv) {

	/* from: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messageboxa
     int MessageBoxA(
         [in, optional] HWND   hWnd,
         [in, optional] LPCSTR lpText,
         [in, optional] LPCSTR lpCaption,
         [in]           UINT   uType
     );
	 */
	MessageBoxW(
		NULL,
		L"MY FIRST MESSAGEBOX!",
		L"HAČIKO ČŽŠĐĆ čžćšđ",
		MB_ICONEXCLAMATION | MB_OKCANCEL
	);

	return EXIT_SUCCESS;
}

