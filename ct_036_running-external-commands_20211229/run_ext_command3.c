#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char *argv[]) {

	char message[100] = "###################\n";
	strcat(message,     "# *** Success *** #\n");
	strcat(message,     "###################\n");

	/* loads the process of external command and runs it
	 * It does not return to previous process. So we create
	 * new proces and run the exec command in child proces,
	 * and in parent process we wait for child process to
	 * finish, and then run postprocessung.
	 */

	int pid1 = fork();

	if (pid1 == 0) {
		printf("--- Executing ping -c5 google.com ---\n");
		int err1 = execlp(
		"pingr",
		"ping",
		"-c",
		"5",
		"google.com",
		NULL
		);

		if (err1 == -1) {
			printf("ERROR: Could not execute command!\n");
			return 0;
		}
	
	} else {
		wait(&pid1);
		printf("%s", message);
	}

	int pid2 = fork();
	

/*
 * 	if (pid2 == 0) {
 * 		printf("\n--- Executing firefox http://www-google.si ---\n");
 * 		int err2 = execlp(
 * 		"firefox",
 * 		"firefox",
 * 		"http://www.google.si",
 * 		NULL
 * 		);
 */

 	if (pid2 == 0) {
 		printf("\n--- Executing firefox http://www-google.si ---\n");
 		int err2 = execlp(
 		"bash",
 		"bash",
		"-c",
 		" ( firefox http://www.google.si) &",
 		NULL
 		);


		if (err2 == -1) {
			printf("ERROR: Could not execute command!\n");
			return 0;
		}

	} else {
		wait(&pid2);
		printf("%s", message);
	}

	printf("Done for all!\n");
	

	return 0;
}

