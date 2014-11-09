"""
*******************
Problem 1

Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

*******************
Pass

*******************

*******************
"""

def calc(a, b, limit):

    sum = 0
    for i in range(limit):
        if i%a == 0 or i%b ==0:
            sum += i

    return sum

def main():
    print calc(3, 5, 1000)

if __name__ == '__main__': main()
