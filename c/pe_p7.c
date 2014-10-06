/*
*******************
Problem 7

10,001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 
What is the 10,001st prime number?

*******************
Pass

*******************

*******************
*/

#include <stdio.h>

int calc(void){

    int num = 2;
    int count = 0;
    int no_prime;

    while (1){
        no_prime = 0;
        for (int i = 2; i < num; i++){
            if (num % i == 0){
                no_prime = 1;
                break;
            }
        }
        if (!no_prime){
            count++;
        }
        if (count == 10001){
            break;
        }
        num++;
    }
    return num;
}


int main(void){

    printf("%d", calc());

    return 0;
}
