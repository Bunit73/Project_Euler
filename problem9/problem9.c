//Benjamin Ford
//Problem 9: https://projecteuler.net/problem=9
//gcc -o prob9 problem9.c -lm -fopenmp
//TODO FIX

#include <stdio.h>
#include <omp.h>
#include <math.h>

#define SOLUTION	1000

int main(int argc, char *argv[]){
	int a, b, c;
	
	printf("%s\n","Brute Force");
	for(a=0; a < 1000; a++){
		for(b=0; b < 1000; b++){
			for(c=0; c < 1000; c++){
				if(testSol(a,b,c,SOLUTION)){
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
	
	return 0;
}

int testSol(int a, int b, int c, int val){
	if((((a*a) * (b*b)) == (c*c)) &&(a < b) && (b < c) && (a + b + c == val)){
		return 1;
	}
	return 0;
}