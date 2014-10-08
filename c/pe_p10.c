/*
*******************
Summation of primes

Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*******************
Pass

*******************

*******************
*/

#include <stdio.h>

long long calc(void){

    long long sum = 0;
    int prime;
    int count;

    for (long long num = 2; num < 2000000; num++){
        count++;
        prime = 1;
        for (long long diver = 2; diver < num/2; diver++){
            if (num % diver == 0){
                prime = 0;
                break;
            }
        }
        if (count == 1000){
            printf("%lld\n", num);
            count = 0;
        }
        if (prime){
            //printf("%lld\n", num);
            sum += num;
        }
    }
    return sum;
}

int main(void){

    printf("%lld", calc());

    return 0;
}
