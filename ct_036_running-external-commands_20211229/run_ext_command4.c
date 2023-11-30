#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int status = 0;

int main (int argc, char *argv[]) {

	char message[100] = "###################\n";
	strcat(message,     "# *** Success *** #\n");
	strcat(message,     "###################\n");

	int fd[2];

	if (pipe(fd) == -1) {
		printf("ERROR: Could not open the pipe!\n");
	}

	int pid1 = fork();

	if (pid1 == 0) {
		close(fd[0]);
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
			int st1 = 1;
			write(fd[1], &st1, sizeof(int));
			close(fd[1]);
			printf("ERROR: Could not execute command!\n");
			return 0;
		}
	
	} else {
		close(fd[1]);
		int st2 = 0;
		read(fd[0], &st2, sizeof(int));
		close(fd[0]);
		*(&status) = st2;
		wait(&pid1);
		if (status == 0) {
			printf("%s", message);
		}
	}

	// *(&status) = 0;
	int fd2[2];

	if (pipe(fd2) == -1) {
		printf("ERROR: Could not open the pipe!\n");
	}

	int pid2 = fork();

	if (pid2 == 0) {
		close(fd2[0]);
		printf("\n--- Executing firefox http://www-google.si ---\n");
		int err2 = execlp(
		"firefox",
		"firefox",
		"http://www.google.si",
		NULL
		);


		if (err2 == -1) {
			int st3 = 1;
			write(fd2[1], &st3, sizeof(int));
			close(fd2[1]);
			printf("ERROR: Could not execute command!\n");

			return 0;
		}

	} else {
		close(fd2[1]);
		int st4 = 0;
		read(fd2[0], &st4, sizeof(int));
		close(fd2[0]);
		*(&status) = st4;
		wait(&pid2);
		if (status == 0) {
			printf("%s", message);
		}
	}

	printf("Done for all!\n");
	

	return 0;
}

