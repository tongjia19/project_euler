/*
*******************
Problem 5

Smallest multiple

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*******************
Pass

*******************

*******************
*/

#include <stdio.h>

int calc(void){

    int num = 20;
    int found;

    while(1){
        found = 1;
        for (int i = 1; i <= 20; i++){
            if (num % i != 0){
                found = 0;
                break;
            }
        }
        if (found){
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
