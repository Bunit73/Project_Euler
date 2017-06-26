//Benjamin Ford
//Problem 3: https://projecteuler.net/problem=3
//gcc -o prob3 problem3.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

#define PRIME_NUM   600851475143 

int getFirstPrime(unsigned long long);

int main(int argc, char *argv[]){
	unsigned int largest = 0;
	unsigned long long i = 0;
	
	//Timers
    double time0, time1, timeTaken = 0.;
	
	time0 = omp_get_wtime();

	i = PRIME_NUM;
	while(i != 1){
		largest = getFirstPrime(i);
		i = i/largest;
	}
	
	time1 = omp_get_wtime();
	timeTaken = time1 - time0;
	
	printf("largest: %d Time Taken: %8.8lf\n",largest, timeTaken);
	
	return 0;
}

int getFirstPrime(unsigned long long num){
	int i;
	for(i = 2; i < num; i++){
		if(num % i == 0){
			return i;
		}
	}
}