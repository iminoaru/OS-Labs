#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    printf("rc is %d\n" , rc);
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("rc == 0 ,  I am child (pid:%d)\n", (int) getpid());
    } else {
        // parent and child 
        printf("rc > 0 ,  I am parent of %d (pid:%d)\n",
	       rc , (int) getpid());
// 'rc' is the pid of the child processes
    }
    return 0;
}
