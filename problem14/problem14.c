//Benjamin Ford
//Problem 12: https://projecteuler.net/problem=1
//gcc -o prob14 problem14.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

#define limit 10000000

int getSeq(int);

int main(int argc, char *argv[]){
	int maxValue = 0;
	int longest = 0;
	int i = 0;
	double time0, time1, timeTaken;
	time0 = omp_get_wtime();
	
	omp_set_num_threads( 8 );
	
	#pragma omp parallel default(none), shared(maxValue, longest), private(i)
	{
		#pragma omp for schedule(static)
		for(i = limit; i > 0; i--)
		{
			int tempVal = 0;
			int tid;
			tempVal = getSeq(i);
			tid = omp_get_thread_num();
			#pragma omp critical
			{
				if(tempVal > maxValue){
					maxValue = tempVal;
					longest = i;
				}
			}
		}
	}
	time1 = omp_get_wtime();
	timeTaken = time1 - time0;
	printf("Longest: %d Time Taken: %8.8lf\n",longest, timeTaken);
 	
	return 0;
}

int getSeq(int num){
	int ctr = 1;
	long val = num;
	if(val < 1){
		return 0;
	}
	
	while(val != 1){
		
		ctr++;
		if(val % 2 == 0){
			val = val/2;
		}
		else{
			val = 3*val + 1;
		}
	}
	
	return ctr;
}