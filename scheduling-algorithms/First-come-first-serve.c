/*1. Write a program in C to implement the concept of First Come First Serve Scheduling
(assuming the arrival time zero for all the process) algorithm for the following set of process to compute
(i) Average Turn Around Time [comp - arrival]
(ii) Average Waiting Time [turn around - burst]
(iii) Average Response Time [first exec - arrival]
Process		Burst time
P1		    6
P2		    2
P3		    8
P4		    3
P5		    4
*/

#include <stdio.h>
int main(){

    int burst[5] = {6 , 2 , 8 , 3 , 4};
    const int arrival = 0;

    int completion[5];

    completion[0] = burst[0];
    for(int i = 1 ; i < 5 ; i++){
        completion[i] = burst[i] + completion[i-1];
    }

    for(int i = 0 ; i < 5 ; i++){
        int turnAround = completion[i] - arrival;
        printf("turn around for p%d: %d\n",i+1, turnAround);

        int waiting = turnAround - burst[i];
        printf("waiting time for p%d: %d\n",i+1, waiting);

        int response = completion[i] - burst[i] - arrival;
        printf("response time for p%d: %d\n\n",i+1, response);
    }

    return 0;
}

