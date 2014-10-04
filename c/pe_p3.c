/*
*******************
Problem 3

Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*******************
Pass

*******************
For large numbers, use long or long long.

*******************
*/

#include <stdio.h>

int calc(long long num){

	int i = 2;
	
	do{
		if (num%i == 0){
			return calc(num/i);
			break;
		}
		else{
			i++;
		}
	}while(i < num/2);
	
	return num;
}

int main(void){

        int i;
        long long num = 600851475143;

        i = calc(num);

        printf("%i", i);

        return 0;
}

