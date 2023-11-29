/*
 * from cd_088_ ...
 */
#include <unistd.h>    // getcwd
#include "daysdiff.h"  // must be after struct Date declaration because it uses it! // ??

const char *fname = "ROJSTNIDNEVI.txt"; // getcwd

char *abspath(char *argv0);

/* =================== MAIN ============================== */
/*
int main(int argc, char **argv) {
	
	setlocale(LC_ALL, "sl_SI.utf-8");

	char path1[256];
	// wchar_t path2[256];
	strcpy(path1, abspath(argv[0]));
	strcat(path1, "/");
	strcat(path1, fname);
	// mbstowcs(path2, path1, 256);
	// wprintf(L"%ls\n", path2);

	return 0;
}
*/

char *abspath(char *argv0) {
	char path_save[PATH_MAX];
	char abs_exe_path[PATH_MAX];
	char *p;
	char *abspth;

	if(!(p = strrchr(argv0, '/'))) {
		getcwd(abs_exe_path, sizeof(abs_exe_path));
	} else {
		*p = '\0';
		getcwd(path_save, sizeof(path_save));
		chdir(argv0);
		getcwd(abs_exe_path, sizeof(abs_exe_path));
	}

	abspth = abs_exe_path;
	return abspth;
}

