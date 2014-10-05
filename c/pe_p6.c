/*
*******************
Problem 6

Sum square difference

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*******************
Pass

*******************

*******************
*/

#include <stdio.h>

int sum_of_square(void){

    int result = 0;

    for (int i = 1; i <= 100; i++){
        result += i*i;
    }

    return result;
}

int square_of_sum(void){

    int result = 0;

    for (int i = 1; i <= 100; i++){
        result += i;
    }
    result = result*result;

    return result;
}

int main(void){

    printf("%d", square_of_sum() - sum_of_square());

    return 0;
}
