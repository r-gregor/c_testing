#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char path_save[PATH_MAX];
	char abs_exe_path[PATH_MAX];
	char *p;

	if(!(p = strrchr(argv[0], '/'))) {
		getcwd(abs_exe_path, sizeof(abs_exe_path));
	} else {
		*p = '\0';
		getcwd(path_save, sizeof(path_save));
		chdir(argv[0]);
		getcwd(abs_exe_path, sizeof(abs_exe_path));
	}

	printf("Absolute path to executable is: %s\n", abs_exe_path);
	return 0;
}

