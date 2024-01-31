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
    int n;
    scanf("%d" , &n);


    int burst[n];

    for(int i = 0 ; i < n ; i++){
	    scanf("%d" , &burst[i]);
    }
    const int arrival = 0;

    int completion[n];

    completion[0] = burst[0];
    for(int i = 1 ; i < n ; i++){
        completion[i] = burst[i] + completion[i-1];
    }

    int turnAroundAvg = 0 , waitingAvg = 0 , responseAvg = 0;


    for(int i = 0 ; i < n ; i++){
        int turnAround = completion[i] - arrival;
	turnAroundAvg += turnAround;
        printf("turn around for p%d: %d\n",i+1, turnAround);

        int waiting = turnAround - burst[i];
	waitingAvg += waiting;
        printf("waiting time for p%d: %d\n",i+1, waiting);

        int response = i ? completion[i-1] : 0;
	responseAvg += response;
        printf("response time for p%d: %d\n\n",i+1, response);
    }

    printf("\nturnAround Average : %d" , turnAroundAvg / n);
    printf("\nwaiting Average : %d" , waitingAvg / n);
    printf("\nresponse Average : %d" , responseAvg / n);


    return 0;
}

