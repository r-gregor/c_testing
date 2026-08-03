/*
 * testport.c
 *     from: '01 Hacking like it's 1999'
 *           https://www.youtube.com/watch?v=9mTiiTyXlhk
 */
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

bool testport(char *ip, unsigned short port);

/* main */
int main(int argc, char **argv) {
	char *ip;
	unsigned short int port;
	unsigned int pid;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <ip> <port>\n", *argv);
		return(-1);
	}

	ip = argv[1];
	port = (unsigned short int)atoi(argv[2]);

	pid = fork();
	
	/* if pid =! 0 --> NOT a child --> kill! */
	/* $> man 2 kill: include: 'signal.h', int kill(pid_t pid, int sig) */
	if (pid) {
		sleep(2);
		kill(pid, SIGTERM);
		wait(0);

	} else {
		/* we are in child process */
		if (testport(ip, port)) { /* returns boolean: include 'stdbool.h' */
			printf("%s:%hd\n", ip, (unsigned short int)port);
			exit(0);
		}
	}





	return 0;
} /* end main */


bool testport(char *ip, unsigned short port) {
	struct sockaddr_in sock;
	signed int ret;
	unsigned int s;

	/* SOCK_STREAM --> tcp connction type */
	/* 0 for protocol: unspecified: default for connection type is used */
	ret = socket(AF_INET, SOCK_STREAM, 0);
	if (ret < 0) {
		return false;
	} else {
		s = (unsigned short int)ret;
	}

	sock.sin_family = AF_INET;
	sock.sin_port = htons((int)port); /* put into correct byte order: big/little-endian */
	                                  /* man arpa_inet.h: uint16_t htons(uint16_t);
	                                                      include 'arpa/inet.h' */
	sock.sin_addr.s_addr = inet_addr(ip);

	/* man connect: int connect (int, const struct sockaddr *, socklen_t); */
	ret = connect((int)s, (struct sockaddr *)&sock, sizeof(sock)); 
	close((int)s);

	if (ret) {
		return false;
	} else {
		return true;
	}
}

