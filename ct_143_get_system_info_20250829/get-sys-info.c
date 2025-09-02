/*
 * filename: get-sys-info.c
 * last change: 20250902 (d)
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <stdlib.h>

#define MAX_CHARS 256

char * cuserid(char *);

struct sysinfo sys_info;
typedef struct sysinfo * SINFO_ptr ;

int main(int argc, char **argv) {

	char host_name[MAX_CHARS];
	if (gethostname(host_name, MAX_CHARS) != 0) {
		printf("[ERROR] clould not get hostname\n");
		return -1;
	}

	// char *user_name = getlogin(); // works on CYGWIN
	char user_name[256];
    cuserid(user_name);
	if (user_name == NULL) {
		printf("[ERROR] could not get username\n");
		// return -1;
	}


	if (sysinfo(&sys_info) != 0) {
		printf("[ERROR] could not get system info\n");
		return -1;
	}

	/* SETUP */
	int psize             = getpagesize();
	SINFO_ptr si          = &sys_info;
	long uptime           = si->uptime;
	unsigned int mem_unit = si->mem_unit;

	/* OUTPUT */
	int plcs = 16;
	printf("%-*s %s\n",plcs, "Hostname:", host_name);
	printf("%-*s %s\n",plcs, "User:", user_name);
	printf("%-*s %d kB (%d B)\n", plcs, "Page size:", psize/1024, psize);
	printf("%-*s %ld seconds\n", plcs, "Uptime:", uptime);
	printf("%-*s %u kB (%u B)\n", plcs, "Mem unit size:", mem_unit/1024, mem_unit);

	printf("---\n");
	/* from https://stackoverflow.com/questions/23323438/get-linux-system-information-in-c */
#if 0
#ifndef _WIN32
#include <linux/sysctl.h>
	int _sysctl(struct __sysctl_args *args );

#define OSNAMESZ 100
	struct __sysctl_args args;
	char osname[OSNAMESZ];
	size_t osnamelth;
	int name[] = { CTL_KERN, KERN_OSTYPE };

	memset(&args, 0, sizeof(struct __sysctl_args));
	args.name = name;
	args.nlen = sizeof(name)/sizeof(name[0]);
	args.oldval = osname;
	args.oldlenp = &osnamelth;

	osnamelth = sizeof(osname);

	if (syscall(SYS__sysctl, &args) == -1) {
		perror("_sysctl");
		exit(EXIT_FAILURE);
	}
	printf("This machine is running %*s\n", osnamelth, osname);
#endif
#endif

#include <sys/utsname.h>

    struct utsname buff;
	if (uname(&buff) != 0) {
		printf("[ERROR]i could not get uname info");
		return -1;
	}

	printf("%-*s %s\n", plcs, "sysname:", buff.sysname);
	printf("%-*s %s\n", plcs, "nodename:", buff.nodename);
	printf("%-*s %s\n", plcs, "release:", buff.release);
	printf("%-*s %s\n", plcs, "version:", buff.version);
	printf("%-*s %s\n", plcs, "machine:", buff.machine);
	printf("---\n");
	
	// int r=system("cat /proc/1/status");


	return 0;
}
