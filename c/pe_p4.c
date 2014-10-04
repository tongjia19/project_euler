/*
*******************
Problem 4

Largest palindrome product

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*******************
Pass

*******************
Learnt how to convert int to char.
    sprintf(num_char, "%d", result);

Have to understand case that 933*933 < 932*999, and so have to replace result with larger result.


*******************
*/

#include <stdio.h>
#include <string.h>

int calc(void){

	int num = 999;
    int result;
    int largest_result = 0;
    char num_char[]="999999";
    int found;

	for(int i = 999; i >= num; i--){
	    found = 1;

		result = num*i;
		sprintf(num_char, "%d", result);

	    for (int j = 0; j < 3; j++){
	        if (num_char[j] != num_char[5-j]){
	            found = 0;
	            break;
	        }
	    }

	    if (found){
            if (result > largest_result){
                largest_result = result;
            }
	    }

        if (i == num){
            num -= 1;
            if (num*999 < largest_result){
                break;
            }
            i = 1000;
        }
	}

	return largest_result;
}


int main(void){

    printf("%d", calc());

    return 0;
}
