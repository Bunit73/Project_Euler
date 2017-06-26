//Benjamin Ford
//Problem 1: https://projecteuler.net/problem=1
//gcc -o prob1 problem1.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
	int sum, i = 0;
	
	//Timers
    double time0, time1, timeTaken = 0.;

	time0 = omp_get_wtime();
	for(i = 0; i < 1000; i++){
		if((i % 3 == 0) || (i % 5 == 0)){
			sum += i;
		}
	}
	time1 = omp_get_wtime();
	
	timeTaken = time1 - time0;
	
	printf("Sum: %d Time Taken: %8.8lf\n",sum, timeTaken);
	
	return 0;
}