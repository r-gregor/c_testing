#include <stdlib.h>		// system(), malloc(), free()
#include <stdio.h>		// snprintf(), puts(), printf()
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>		// stat(), unlink(), close(), read()
#include <errno.h>		// errno
#include <string.h>		// strerror()
#include <assert.h>		// assert()
#include <fcntl.h>		// open()

// temporary file name
#define TEMP_SELF "/tmp/self"

// most library functions return error code in errno
// use common "subroutine" to print the error reason
// and exit with error code
#define PROCESS_ERRNO(msg)		\
	int err = errno;			\
	printf("Failed to " msg " -"\
		" error %i (%s)\n", err,\
		strerror(err));			\
	return_code = 1;			\
	goto exit;

int main() {
	int return_code = 0;
	const char temp[] = TEMP_SELF;
	const char get_self[] = "cat /proc/self/status " \
		"| grep PPid | grep -o [0-9]* " \
		"| xargs -I{} cat /proc/{}/status | grep PPid " \
		"| grep -o [0-9]*  > " TEMP_SELF;
	const char fmt[] = "cat /proc/%s/%s | tr '\\0' ' '";
	const char info[] = "cmdline";
	int cmdline_len;
	char *cmdline = NULL;
	char *mypid = NULL;
	struct stat link_info;
	int result;
	int fd = -1;

	// workaround - according to man 2 lstat we can't
	// get the right size of the link/file in /proc,
	// which means that we cannot determine the actual
	// size of "/proc/self", so we have to find out
	// the current process`s directory in /proc by writing
	// the relevant identifier to a temporary file and
	// reading it back
	result = system(get_self);
	if (result == -1) {
		PROCESS_ERRNO("read self link");
	}
	// get the temporary file's size to allocate memory
	// as needed
	result = stat(temp, &link_info);
	if (result == -1) {
		PROCESS_ERRNO("read temp stats");
	}
	mypid = malloc(link_info.st_size + 1);
	if (mypid == NULL) {
		PROCESS_ERRNO("allocate memory for pid");
	}
	// read the current process pid into allocated space
	fd = open(temp, O_RDONLY);
	if (fd == -1) {
		PROCESS_ERRNO("open temp file");
	}
	result = read(fd, mypid, link_info.st_size - 1);
	if (result == -1) {
		PROCESS_ERRNO("read the temp file");
	}
	// let's assume we have read exactly what we
	// asked for
	// it`s a homework, not an enterprise solution
	assert(result == link_info.st_size - 1);
	mypid[result] = '\0';
	// allocate space for final query
	cmdline_len = sizeof(fmt) + link_info.st_size
		+ sizeof(info);
	cmdline = malloc(cmdline_len);
	if (cmdline == NULL) {
		PROCESS_ERRNO("allocate memory for command");
	}
	// construct the final query string
	snprintf(cmdline, cmdline_len, fmt, mypid, info);
	// print the information
	result = system(cmdline);
	if (result == -1) {
		PROCESS_ERRNO("execute command");
	}

	// per man puts it writes a newline at the end
	// of the string
	puts("");
exit:
	// common cleanup path
	// notes: free() happily accepts NULL
	// close() and unlink() are OK to fail
	close(fd);
	unlink(temp);
	free(mypid);
	free(cmdline);
	return return_code;
}
