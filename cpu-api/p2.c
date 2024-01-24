#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
	sleep(1);
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
	printf( "wc ==  %d\n" , wc);
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
	//waits till the completion of child process, then wc stores the 
	//pid of child after termination, after which the parent process is executed.
    }
    return 0;
}
