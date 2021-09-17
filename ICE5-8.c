#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int swap_digit_pairs(int n) {
    bool is_negative = (n < 0 ) ? true : false; //Checks if the value is negative
    n = abs(n); //Absolutes the value regardless

    int value = 0;
    int count = 1;

    while (n >= 10) { //This block will only execute if there is a pair
        int d1 = n % 10; //right digit of the pair
        int d2 = (n / 10) % 10; //left digit of the pair

        value = value + (d1 * (int)pow(10, count)) + (d2 * (int)pow(10, count - 1));
        count = count + 2;

        n = n / 100; //As dealing with 2 numbers at a time
    }
    value = value + (n * (int)pow(10, count-1));

    return (is_negative == true) ? -value : value;
}

int main(void) {
    {
        printf("Test 1\n");
        int result = swap_digit_pairs(1);
        printf("Expected:1\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 2\n");
        int result = swap_digit_pairs(32);
        printf("Expected:23\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 3\n");
        int result = swap_digit_pairs(90);
        printf("Expected:9\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 4\n");
        int result = swap_digit_pairs(971);
        printf("Expected:917\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 5\n");
        int result = swap_digit_pairs(382818);
        printf("Expected:838281\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 6\n");
        int result = swap_digit_pairs(-13);
        printf("Expected:-31\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 7\n");
        int result = swap_digit_pairs(-1347);
        printf("Expected:-3174\n");
        printf("Actual  :%d\n\n", result);
    }
}