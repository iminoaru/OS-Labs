/*    1. Write a program in C to implement the concept of Round Robin algorithm 
 (with user defined Time Quantum) with zero arrival time for all the process for 
the following set of process to compute: 
    (i) Average Turn Around Time
    (ii) Average Waiting Time
    (iii) Average Response Time
Process		Burst tim
P1		6
P2              2
P3		8
P4		3
P5		4
*/


#include <stdio.h>

int main(){
	int n;
	printf("Enter number of processes : ");
	scanf("%d" , &n);

	int burst[n];
	int pos[n];
	int qsize = 0;
	for(int i = 0 ; i < n ; i++){
		printf("\nEnter burst time of process p%d: ", i+1);
		scanf("%d" , &burst[i]);
		
		pos[i] = i+1;

		qsize += burst[i];
	}
	int gsum = qsize*2;
	int tc;
	printf("\nEnter time quantum: ");
	scanf("%d" , &tc);

	qsize = qsize/tc + 1;
	int q[qsize];
	int head = 0 , tail = n-1;

	for(int i = 0 ; i < n ; i++){
		q[i] = burst[i];
	}
	

	while(gsum != 0){
		
		int item = q[head] >= tc ? q[head] - tc : 0 ;
		
		if(item > 0){
			q[tail+1] = item;
			tail++;
			gsum -= q[head] - q[tail+1];		
		}
		 head++;
		
	}

	printf("Ready Queue: ");
	for(int i = 0 ; i < qsize ; i++){
                printf("%d  " , q[i]);

        }

	return 0;
}
