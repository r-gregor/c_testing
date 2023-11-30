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

	int pid = fork();

	if (pid == 0) {
		printf("--- Running 'ping -c 5 google.com' ---\n");
		execlp(
		"ping",
		"ping",
		"-c",
		"5",
		"google.com",
		NULL
		);

	/*
	 * 	execlp(
	 * 	"firefox",
	 * 	"firefox",
	 * 	"http://www.google.si",
	 * 	NULL
	 * 	);
	 */

	} else {
		wait(NULL);
		// printf("Success!\n");
		printf("\n%s", message);
	}

	return 0;
}

