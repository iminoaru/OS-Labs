/*2. Write a program in C to implement the concept of First Come First Serve Scheduling algorithm
for the following set of process to compute
(iv) Average Turn Around Time
(v) Average Waiting Time
(vi) Average Response Time
Process		Burst time	arrival time
P1		    6		    2
P2		    2		    5
P3		    8		    1
P4		    3		    0
P5		    4		    4
*/

//p4 p3 p1 p5 p2

#include <stdio.h>

int main(){

    int burst[5] = {6 , 2 , 8 , 3 , 4};
    int arrival[5] = {2 , 5 , 1 , 0 , 4};
    int pos[5] = {1 , 2 , 3 , 4 , 5};

    int completion[5];

    // sorting all the arrays according to arrival time
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 - i ; j++){

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
    for(int i = 1 ; i < 5 ; i++){
        completion[i] = burst[i] + completion[i-1];
    }

    for(int i = 0 ; i < 5 ; i++){
        int turnAround = completion[i] - arrival[i];
        printf("turn around for p%d: %d\n",pos[i], turnAround);

        int waiting = turnAround - burst[i];
        printf("waiting time for p%d: %d\n",pos[i], waiting);

        int response = completion[i] - burst[i] - arrival[i];
        printf("response time for p%d: %d\n\n",pos[i], response);
    }

    return 0;
}

