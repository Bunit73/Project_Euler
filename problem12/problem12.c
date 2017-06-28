//Benjamin Ford
//Problem 12: https://projecteuler.net/problem=12
//gcc -o prob12 problem12.c -lm -fopenmp

#include <stdio.h>
#include <omp.h>

int main(int argc, char * argv[]){
	int i = 0, count = 0;
	long triNumber = 0;
	double time0, time1, timeTaken;
	time0 = omp_get_wtime();
	
	do{
		i++;
		triNumber = sumOfVal(i);
		count = countDivisor(triNumber);
		printf("%ld %d\n",triNumber,count);
	}while(count < 500);
	time1 = omp_get_wtime();
	timeTaken = time1 - time0;
	printf("Larges Triangle Num > 500 DIV: %ld Time Taken: %8.8lf\n",triNumber, timeTaken);
	
	return 0;
}

int sumOfVal(int num){
	return (num) * (num+1)/2; 
}

int countDivisor(int num){
	int i, cnt = 0;
	for(i=1; i <= num; i++){
		if(num % i == 0){
			cnt++;
		}
	}
	return cnt;
};