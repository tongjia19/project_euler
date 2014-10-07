/*
*******************
Special Pythagorean triplet

Problem 9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*******************
Pass

*******************

*******************
*/

#include <stdio.h>

int calc(void){

    for (int a = 0; a < 333 ; a++){
        for (int b = 1; b < 500; b++){
            int c = 1000 - a - b;
            if ((a*a + b*b) == c*c){
                //printf ("%d, %d, %d\n", a, b, c);
                return a*b*c;
            }
        }
    }
    return 0;
}


int main(void){

    printf("%d", calc());

    return 0;
}
