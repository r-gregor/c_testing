#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define _XOPEN_SOURCE 500

/* app_path
 * get application path, it need argv[0], and store the result to path.
 */
char * app_path(char * path, const char * argv0) {
    char buf[PATH_MAX];
    // char * pos;
    if (argv0[0] == '/') {    // run with absolute path
        strcpy(buf, argv0);
    } else {    // run with relative path
        if(getcwd(buf, PATH_MAX) == NULL) {
            perror("getcwd error");
            return NULL;
        }
        char *myfile = "ROJSTNIDNEVI.txt";
        strcat(buf, "/");
        // strcat(buf, argv0);
        strcat(buf, myfile);
    }
    if (realpath(buf, path) == NULL) {
        perror("realpath error");
        return NULL;
    }
    return path;
}

int main(int argc, char **argv) {
    char mypath[PATH_MAX];
    if (app_path(mypath, argv[0]) != NULL) {
        printf("%s\n", mypath);
    }

    return 0;
}

