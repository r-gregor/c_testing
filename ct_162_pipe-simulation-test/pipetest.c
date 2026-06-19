/*
 * fname: pipetest.c
 * simulating command:
 *      $> ping -c 5 <url> | grep "round"
 * v1_20260619
 * last: 20260619
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv) {

	/* initialize fd for pipe */
	int fd[2];
	if (pipe(fd) == -1) {
		return 1;
	}

	/* fork/clone the current process for 'ping' comand */
	int pid1 = fork();
	if (pid1 < 0) {
		return 2;
	}

	/* child process: for 'ping' command */
	if (pid1 == 0) {
		// char *URL1 = "google.com"; // try home
		char *URL2 = "10.99.10.1";    // EN

		dup2(fd[1], STDOUT_FILENO);

		/* closing child's copies of fd-s */
		close(fd[0]);
		close(fd[1]);

		execlp("ping", "ping", "-c", "5", URL2, NULL);
	}

	/* fork/clone the current process for 'grep' comand */
	int pid2 = fork();
	if (pid2 < 0) {
		return 3;
	}

	/* child process: for 'grep' command */
	if (pid2 == 0) {
		dup2(fd[0], STDIN_FILENO);

		/* closing child's copies of fd-s */
		close(fd[0]);
		close(fd[1]);

		execlp("grep", "grep", "round", NULL);
	}

	/*
	 * closing fd-s of parent process
	 * or 'grep' command will wait for input
	 * and not finish executing
	 */
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	printf("\n");

	return 0;
}

