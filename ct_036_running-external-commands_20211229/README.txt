from man exec (linux)

NAME
       execl, execlp, execle, execv, execvp, execvpe - execute a file

SYNOPSIS
       #include <unistd.h>

exec[args]
	args ... l - execl(), execlp(), execle()
	             a list of arguments: argv[0], argv[1], ...) must be terminated by NULL

             p - no need to enter path to program (ping instead of /usr/bin/ping) search in $PATH
             
             v - a list of raguments as vector (array) must be terminated by NULL

             e - environment

=================================================================================================
In order to run wait() --> must include:

#include <sys/types.h>
#include <sys/wait.h>
