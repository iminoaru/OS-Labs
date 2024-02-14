/*
1. Write a program in C to implement the concept of Shortest Job First Scheduling algorithm  (Preemptive and Non-Preemptive both) with zero arrival time for all the process for the following set of process to compute: 
(i) Average Turn Around Time
(ii) Average Waiting Time
(iii) Average Response Time
Process		Burst time	
P1		6		
P2		2		
P3		8		
P4		3		
P5		4		

*/
#include <stdio.h>

int main(){
    int n;
    printf("Enter no. of processes: ");
    scanf("%d" , &n);

    int burst[n];
    int pos[n];
    printf("\nEnter process's burst time: ");
    for(int i = 0 ; i < n ; i++){
      scanf("%d" , &burst[i]);
      pos[i] = i+1;
    }
    const int arrival = 0;

    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - 1 - i ; j++){

            if (burst[j] > burst[j + 1]){
                burst[j] = burst[j] + burst[j + 1];
                burst[j + 1] = burst[j] - burst[j + 1];
                burst[j] = burst[j] - burst[j + 1];

                pos[j] = pos[j] + pos[j + 1];
                pos[j + 1] = pos[j] - pos[j + 1];
                pos[j] = pos[j] - pos[j + 1];
            }
        }
    }
  
    int completion[n];

    completion[0] = burst[0];
    for(int i = 1 ; i < n ; i++){
        completion[i] = burst[i] + completion[i-1];
    }

    int turnAroundAvg = 0 , waitingAvg = 0 , responseAvg = 0;


    for(int i = 0 ; i < n ; i++){
        int turnAround = completion[i] - arrival;
  turnAroundAvg += turnAround;
        printf("turn around for p%d: %d\n",pos[i], turnAround);

        int waiting = turnAround - burst[i];
  waitingAvg += waiting;
        printf("waiting time for p%d: %d\n",pos[i], waiting);

        int response = i ? completion[i-1] : 0;
  responseAvg += response;
        printf("response time for p%d: %d\n\n",pos[i], response);
    }

    printf("\nturnAround Average : %d" , turnAroundAvg / n);
    printf("\nwaiting Average : %d" , waitingAvg / n);
    printf("\nresponse Average : %d" , responseAvg / n);



  return 0;
}

/* CONSOLE

Enter no. of processes: 5

Enter process's burst time: 6 2 8 3 4
turn around for p2: 2
waiting time for p2: 0
response time for p2: 0

turn around for p4: 5
waiting time for p4: 2
response time for p4: 2

turn around for p5: 9
waiting time for p5: 5
response time for p5: 5

turn around for p1: 15
waiting time for p1: 9
response time for p1: 9

turn around for p3: 23
waiting time for p3: 15
response time for p3: 15


turnAround Average : 10
waiting Average : 6
response Average : 6

*/
