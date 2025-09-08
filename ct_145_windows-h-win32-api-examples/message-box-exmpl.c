/*
 * filename: message-box-exmpl.c
 * last: 20250908
 */
#include <stdio.h>
#include <string.h>
#include <windows.h>


int main(int argc, char **argv) {


	MessageBoxW(
		NULL,
		L"MY FIRST MESSAGEBOX!",
		L"HAČIKO ČŽŠĐĆ čžćšđ",
		MB_ICONEXCLAMATION | MB_OKCANCEL
	);

	return EXIT_SUCCESS;
}
