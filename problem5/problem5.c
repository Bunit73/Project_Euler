//Benjamin Ford
//Problem 5: https://projecteuler.net/problem=5
//gcc -o prob5 problem5.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

int divByTwenty(int);

int main(int argc, char *argv []){
	int test, i = 0;
	
	//Timers
    double time0, time1, timeTaken = 0.;
	
	time0 = omp_get_wtime();
	
	while(test != 1){
		i++;
		test = divByTwenty(i);
	}
	
	time1 = omp_get_wtime();
	timeTaken = time1 - time0;
	
	printf("Smallest Divisor: %d Time Taken: %8.8lf\n",i, timeTaken);
	
	return 0;
}

int divByTwenty(int num){
	int i;
	
	for(i = 1; i <= 20; i++){
		if(num % i != 0){
			return 0;
		}
	}
	
	return 1;
}