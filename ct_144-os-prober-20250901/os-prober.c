/*
 * os-prober.c
 * last change: 20250901
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

#if defined(__linux__) // any linux distribution
#define PLATFORM "LINUX"
#elif defined(__unix__)
#define PLATFORM "UNIX (other Linux)"
#elif defined(_WIN32)
#define PLATFORM "WINDOWS"
#else
#define PLATFORM "UNKNOWN"
#endif


int main(int argc, char *argv[]) {

	int plcs = 15;
	// puts(PLATFORM);
	printf("[INFO] %-*s %-*s %s\n", plcs, "platform:", plcs +10, PLATFORM, "(defined platform)");
	printf("[INFO] %-*s %-*s %s\n", plcs, "OS:", plcs + 10, getenv("OS"), "(\"OS\" env)");

	struct utsname sysinfo;
    if (uname(&sysinfo) != 0) {
		printf("[ERROR] could note get sysinfo\n");
	}
	printf("[INFO] %-*s %-*s %s\n", plcs, "sysname:", plcs +10, sysinfo.sysname, "(utsname/sysname)");

	return 0;
}
