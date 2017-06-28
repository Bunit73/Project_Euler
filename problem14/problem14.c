//Benjamin Ford
//Problem 12: https://projecteuler.net/problem=1
//gcc -o prob14 problem14.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
	int maxValue = 0;
	int i = 0;
	
	omp_set_num_threads( 8 );
	
	#pragma omp for 	
    for(i = 1000000; i > 0; i--)
    {
       printf("%d ", i);
    }
	
	maxValue = getSeq(13);
	
	printf("%d\n",maxValue);
	
	return 0;
}

int getSeq(num){
	int ctr = 1;
	long val = num;
	
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