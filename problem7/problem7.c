//Benjamin Ford
//Problem 7: https://projecteuler.net/problem=7
//gcc -o prob7 problem7.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv []){
	int prime, cntr;
	int i = 2;
	
	
	//Timers
    double time0, time1, timeTaken = 0.;
	time0 = omp_get_wtime();
	while(cntr < 10001){
		if(isPrime(i))
		{
			cntr++;
			prime = i;
		}
		i++;
	}
	time1 = omp_get_wtime();
	timeTaken = time1 - time0;
	
	printf("Largest: %d Time Taken: %8.8lf\n",prime, timeTaken);	
	
	return 0;
}

int isPrime(int num){
	int i = 2;
	
	for(i; i < num; i++){
		if(num % i == 0){
			return 0;
		}
	}
	return 1;
}