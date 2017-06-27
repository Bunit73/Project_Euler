//Benjamin Ford
//Problem 5: https://projecteuler.net/problem=6
//gcc -o prob6 problem6.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>
#include <math.h>

int main(int argc, char *argv[]){
	long i, diff, sumOfSquares, squareOfSum = 0;
	
	//Timers
    double time0, time1, timeTaken = 0.;
	
	time0 = omp_get_wtime();
	
	for(i = 0; i <= 100; i++){
		sumOfSquares += pow(i,2);
		squareOfSum++;
	}
	
	diff = pow(squareOfSum,2) - sumOfSquares;
	
	time1 = omp_get_wtime();
	timeTaken = time1 - time0;
	
	printf("Diff: %d Time Taken: %8.8lf\n",diff, timeTaken);	
	
	return 0;
}