//Benjamin Ford
//Problem 9: https://projecteuler.net/problem=9
//gcc -o prob9 problem9.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>
#include <math.h>

#define SOLUTION	1000

int main(int argc, char *argv[]){
	int a, b, c;
	double time0, time1, timeTaken;
	
	printf("%s\n","Brute Force");
	time0 = omp_get_wtime();
	
	for(a=0; a < SOLUTION; a++){
		for(b=a+1; b < SOLUTION; b++){
			for(c=b+1; c < SOLUTION; c++){
				if(testSol(a,b,c,SOLUTION)){
					printf("%d %d %d Product: %d\n",a,b,c, (a*b*c));
					break;
				}
			}
		}
	}
	time1 = omp_get_wtime();
	
	timeTaken = time1 - time0;
	printf("Brute Forece Time Taken: %8.8lf\n", timeTaken);
	return 0;
}

int testSol(int a, int b, int c, int val){
	if((pow(a,2) + pow(b,2) == pow(c,2)) && ((a+b+c) == val )){
		return 1;
	}
	return 0;
}