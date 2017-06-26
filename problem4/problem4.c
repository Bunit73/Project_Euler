//Benjamin Ford
//Problem 4: https://projecteuler.net/problem=4
//gcc -o prob4 problem4.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>


int main(int argc, char *argv []){
	int i, j = 999;
	int num, remainder, rev, orignum,  max = 0;
	//Timers
    double time0, time1, timeTaken = 0.;
	
	time0 = omp_get_wtime();
	for(i = 999; i > 99; i--){
		for(j = 999; j > 99; j--){
			num = i * j;
			orignum = num;
			remainder = 0;
			rev = 0;
			
			while(num != 0){
				remainder = num%10;
				rev = rev*10 + remainder;
				num /= 10;
			}
			
			if(orignum == rev){
				if(orignum > max){
					max = orignum;
				}
			}
		}
	}
	
	time1 = omp_get_wtime();
	timeTaken = time1 - time0;
	
	printf("Max 3 digit sum palidrome: %d Time Taken: %8.8lf\n",max, timeTaken);
	
	return 0;
}