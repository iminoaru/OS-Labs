#include <stdio.h>
#include <stdlib.h>

int rad(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main(){

	int p[5] = {1 , 2 , 3 , 4 , 5};
	int tickets[5] = {60 , 20 , 80 , 30 , 10};
        //int burst[5] = {10 , 15 , 5 , 25 , 40};
	int burst[5] = {10 , 45 , 15 , 25 , 20};

	int pr[5];
	pr[0] = tickets[0];
	for(int i = 1 ; i < 5 ; i++){
		pr[i] = pr[i-1] + tickets[i]; 
	}

	while(burst[0] + burst[1] + burst[2] + burst[3] + burst[4] > 0){
		int rc = rad(0 , pr[4]);
		int tr;
		for(int i = 0 ; i < 5 ; i++){
			if(rc < pr[0]) tr = 0;
			if(rc > pr[i] && rc < pr[i+1]) tr = i+1; 
		}
		if(burst[tr] != 0) {
			burst[tr] -= 5; // taken 5 as the time slot
			 printf("P%d  " , p[tr]);
		}
	}
	return 0;
}
