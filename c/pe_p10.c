/*
*******************
Summation of primes

Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*******************
142913828922
*******************
Pass
*******************
- long long array is no good.. segfaults..
  - Due to stack overflow.
    - Allocates on the stack because it's specified as an array with a constant number of elements
      at compile time. Values are only put on the heap with malloc, new, etc.

- divide by prime nums to find prime num
*******************
*/

#include <stdio.h>

// this one is really slow.. and it's produces a slightly off answer.. hmm
/*
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

    // got this: 142913828926
}
*/

long long calc(void){

    long long sum = 0;
    int prime;
    int prime_nums[2000000];
    int prime_nums_index = 0;
    long long diver;
    //int processed_count = 0;

    // initialize array
    for (int i = 0; i < 2000000; i++){
        prime_nums[i] = 0;
    }

    for (long long num = 2; num < 2000000; num++){
        //processed_count++;
        prime = 1;
        for (long long index = 0; index < 2000000; index++){
            diver = prime_nums[index];
            if (diver == 0){
                break;
            }
            if (num % diver == 0){
                prime = 0;
                break;
            }
        }
        /*if (processed_count == 20000){
            if ((num - 1) == 20000){
                puts("");
            }
            printf("%lld%%\n", ((num - 1)/20000));
            processed_count = 0;
        }*/
        if (prime){
            prime_nums[prime_nums_index] = num;
            prime_nums_index++;
            sum += num;
        }
    }

    return sum;
}

int main(void){

    printf("%lld", calc());

    return 0;
}
