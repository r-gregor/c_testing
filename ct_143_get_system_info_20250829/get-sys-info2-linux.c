
/*
 * filename: get-sys-info2-linux.c
 * from: https://discussions.apple.com/thread/1403763?answerId=6646264022&sortBy=rank#6646264022
 *
 * The sysctl() function is a bit trickier to use but can give you everything you want to know. For instance, to
 * get the size of your physical memory
 * NOT working on EN (WIN)
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <linux/sysctl.h>

#define ARRAY_SIZE(arr)  (sizeof(arr) / sizeof((arr)[0]))

int _sysctl(struct __sysctl_args *args);

#define OSNAMESZ 100

int main(void) {
	int                   name[] = { CTL_KERN, KERN_OSTYPE };
	char                  osname[OSNAMESZ];
	size_t                osnamelth;
	struct __sysctl_args  args;

	memset(&args, 0, sizeof(args));
	args.name = name;
	args.nlen = ARRAY_SIZE(name);
	args.oldval = osname;
	args.oldlenp = &osnamelth;

	osnamelth = sizeof(osname);

	if (syscall(SYS__sysctl, &args) == -1) {
		perror("_sysctl");
		exit(EXIT_FAILURE);
	}
	printf("This machine is running %*s\n", (int) osnamelth, osname);
	exit(EXIT_SUCCESS);
}

