#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

volatile int counter = 0; 
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
	counter++;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    } 
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL); // creates 2 instances and stores it in p1 and p2  
    Pthread_create(&p2, NULL, worker, NULL);
    printf("before pthreads_join   : %d\n", counter);
    Pthread_join(p1, NULL);
printf("after pthreads_join p1  : %d\n", counter);

    Pthread_join(p2, NULL); // joins the 2 instances
printf("after pthreads_join p2   : %d\n", counter);

    printf("Final value   : %d\n", counter);
    return 0;
}
