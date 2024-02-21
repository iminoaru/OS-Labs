#include <stdio.h>

int main(){

    int n;

    printf("Enter number of processes :");
    scanf("%d" , &n);

    int burst[n];
    int priority[n];
    int pos[n];

    int completion[n];

    for(int i = 0 ; i < n ; i++){
            printf("Enter priority of process p%d: ", i+1);
            scanf("%d" , &priority[i]);

            printf("Enter burst Time of process p%d: ", i+1);
            scanf("%d" , &burst[i]);

            pos[i] = i+1;
    }


    // sorting all the arrays according to priority
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - 1 - i ; j++){

            if (priority[j] > priority[j + 1]){
                priority[j] = priority[j] + priority[j + 1];
                priority[j + 1] = priority[j] - priority[j + 1];
                priority[j] = priority[j] - priority[j + 1];

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

    int tA = 0 , wA = 0 , rA =0;

    for(int i = 0 ; i < n ; i++){
        int turnAround = completion[i] - 0;
        tA += turnAround;
        printf("turn around for p%d: %d\n",pos[i], turnAround);

        int waiting = turnAround - burst[i];
        wA += waiting;
            printf("waiting time for p%d: %d\n",pos[i], waiting);

        int response = i ?  completion[i-1] : 0 ;
        rA += response;
        printf("response time for p%d: %d\n\n",pos[i], response);
    }


    printf("Average TurnAround Time: %d\n" , tA/n);
    printf("Average Waiting Time: %d\n" , wA/n);
    printf("Average Response Time: %d\n" , rA/n);

    return 0;
}

