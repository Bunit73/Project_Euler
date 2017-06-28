//Benjamin Ford
//Problem 10: https://projecteuler.net/problem=10
//gcc -o prob10 problem10.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

int isPrime(int);

int main(int argc, char *argv[]){
	int i;
	unsigned long long  sum = 0;
	double time0, time1, timeTaken;
	time0 = omp_get_wtime();
	
	printf("%s\n","Brute Force");
	for(i = 2; i < 2000000; i++){
		if(isPrime(i)){
			sum += i;
		}
	}
	
	time1 = omp_get_wtime();
	
	timeTaken = time1 - time0;
	printf("Brute Forece Sum: %llu Time Taken: %8.8lf\n",sum, timeTaken);	
	
	return 0;
}

int isPrime(int num){
	int i;
	for(i = 2; i < num; i++){
		if(num % i == 0){
			return 0;
		}
	}
	return 1;
}