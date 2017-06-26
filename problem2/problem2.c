//Benjamin Ford
//Problem 2: https://projecteuler.net/problem=2
//gcc -o prob2 problem2.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[]){
	
	//Timers
    double time0, time1, timeTaken = 0.;
	int sum, a, c = 0;
	int b = 1;
	
	time0 = omp_get_wtime();
	while(sum <= 4000000){
		c = b;
		b = a + b;
		if(b%2==0){
			sum += b;
		}
		a = c;
	}
	
	time1 = omp_get_wtime();
	
	timeTaken = time1 - time0;
	
	printf("Sum: %d Time Taken: %8.8lf\n",sum, timeTaken);
	
	return 0;
}