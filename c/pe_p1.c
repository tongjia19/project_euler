/*
*******************
Problem 1

Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

*******************
Fail

*******************
Make sure to not add the numbers that are both multiples of 3 and 5 twice. i.e., 15.

*******************
*/

#include <stdio.h>

int calc1(int num1, int bound){
	
	int i = 1;
	int sum = 0;
	do{
		
		sum += i*num1;
		i++;

	}while(i*num1<bound);
	
	return sum;
}

int calc2(int num1, int num2, int bound){
	
	int i = 1;
	int sum = 0;
	do{
		
		if (i*num1 % num2 != 0){
			sum += i*num1;
		}
		i++;

	}while(i*num1<bound);
	
	return sum;
}

int main(void){

        int num1 = 3;
        int num2 = 5;
        int bound = 1000;
        int sum;

        sum = calc1(num1, bound) + calc2(num2, num1, bound);

        printf("%d", sum);

        return 0;
}

