/*2. Write a program in C to implement the concept of First Come First Serve Scheduling algorithm
for the following set of process to compute
(iv) Average Turn Around Time
(v) Average Waiting Time
(vi) Average Response Time
Process         Burst time      arrival time
P1                  6               2
P2                  2               5
P3                  8               1
P4                  3               0
P5                  4               4
*/

//p4 p3 p1 p5 p2

#include <stdio.h>

int main(){

    int n;
    
    printf("Enter number of processes :");
    scanf("%d" , &n);
    
    int burst[n];
    int arrival[n];
    int pos[n];

    int completion[n];
    
    for(int i = 0 ; i < n ; i++){
            printf("Enter arrival Time of process p%d: ", i+1);
            scanf("%d" , &arrival[i]);
            
            printf("Enter burst Time of process p%d: ", i+1);
            scanf("%d" , &burst[i]);
            
            pos[i] = i+1;
    }


    // sorting all the arrays according to arrival time
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - 1 - i ; j++){

            if (arrival[j] > arrival[j + 1]){
                arrival[j] = arrival[j] + arrival[j + 1];
                arrival[j + 1] = arrival[j] - arrival[j + 1];
                arrival[j] = arrival[j] - arrival[j + 1];

                burst[j] = burst[j] + burst[j + 1];
                burst[j + 1] = burst[j] - burst[j + 1];
                burst[j] = burst[j] - burst[j + 1];

                pos[j] = pos[j] + pos[j + 1];
                pos[j + 1] = pos[j] - pos[j + 1];
                pos[j] = pos[j] - pos[j + 1];
            }
        }
    }

    completion[0] = burst[0];
    for(int i = 1 ; i < n ; i++){
        completion[i] = burst[i] + completion[i-1];
    }
    
    int tA , wA , rA;

    for(int i = 0 ; i < n ; i++){
        int turnAround = completion[i] - arrival[i];
       	tA += turnAround;
       	printf("turn around for p%d: %d\n",pos[i], turnAround);

        int waiting = turnAround - burst[i];
        wA += waiting;
	    printf("waiting time for p%d: %d\n",pos[i], waiting);

        int response = i ?  completion[i-1] - arrival[i] : 0 ;
        rA += response;
       	printf("response time for p%d: %d\n\n",pos[i], response);
    }
    
    
    printf("Average TurnAround Time: %d\n" , tA/n);
    printf("Average Waiting Time: %d\n" , wA/n);
    printf("Average Response Time: %d\n" , rA/n);

    return 0;
}
