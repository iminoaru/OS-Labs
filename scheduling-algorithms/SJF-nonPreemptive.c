/*    2. Write a program in C to implement the concept of Shortest Job First Scheduling algorithm (Preemptive and Non-Preemptive both) for the following set of process to compute: 
    (i) Average Turn Around Time
    (ii) Average Waiting Time
    (iii) Average Response Time
    (iv) CPU Utilization
Process		Burst time	Arrival time
P1		6		2
P2		2		5
P3		8		1
P4		3		7
P5		4		4
*/

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

  int aMin = 1000000;
  for(int i = 0 ; i < n ; i++){
    if(arrival[i] < aMin){
      aMin = arrival[i];
    }
  }
  if(aMin > 0){
	for(int i = 0 ;  i < n ; i++){
	arrival[i] -= aMin;
}	

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
    
    int tA=0 , wA=0 , rA=0;

    for(int i = 0 ; i < n ; i++){
        int turnAround = completion[i] - arrival[i];
	
       	tA += turnAround;
       	printf("turn around for p%d: %d\n",pos[i], turnAround);

        int waiting = turnAround - burst[i];
        wA += waiting;
	      printf("waiting time for p%d: %d\n",pos[i], waiting);

        int response = i ? completion[i-1] - arrival[i] : 0 ;
        rA += response;
       	printf("response time for p%d: %d\n\n",pos[i], response);
    }
    
    
    printf("Average TurnAround Time: %d\n" , tA/n);
    printf("Average Waiting Time: %d\n" , wA/n);
    printf("Average Response Time: %d\n" , rA/n);

    return 0;
}

/* CONSOLE

Enter number of processes :5
Enter arrival Time of process p1: 2
Enter burst Time of process p1: 6
Enter arrival Time of process p2: 5
Enter burst Time of process p2: 2
Enter arrival Time of process p3: 1
Enter burst Time of process p3: 8
Enter arrival Time of process p4: 7
Enter burst Time of process p4: 3
Enter arrival Time of process p5: 4
Enter burst Time of process p5: 4

turn around for p3: 8
waiting time for p3: 0
response time for p3: 0

turn around for p1: 13
waiting time for p1: 7
response time for p1: 7

turn around for p5: 15
waiting time for p5: 11
response time for p5: 11

turn around for p2: 16
waiting time for p2: 14
response time for p2: 14

turn around for p4: 17
waiting time for p4: 14
response time for p4: 14

Average TurnAround Time: 13
Average Waiting Time: 9
Average Response Time: 9

*/

