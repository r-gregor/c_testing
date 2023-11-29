#ifndef FILE_ABSPATH_H_
#define FILE_ABSPATH_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h> // getcwd()
#include <limits.h> // PATH_MAX

void file_abspath(char *path1, char *fname, char *argv0);

// store absolute path of fname into fpath,
// with argv[0] as current location
//
// usage:
// in main(int argc, char **argv):
//     char *fname ="...";
//     char fpath[PATH_MAX];
//     file_abspath(fpath, fname, argv[0]);
//
// now fpath contains absolute path to file

void file_abspath(char *fpath, char *fname, char *argv0) {
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

	strcpy(fpath, abspth);
	strcat(fpath, "/");
	strcat(fpath, fname);
}

#endif

