#include <stdio.h>
#include <math.h>

void print_expanded_form(int n) {
    int num = n;
    int count = 0;
    int pali = 0;

    if(n <= 0) {
        printf("Invalid Input!");
        return;
    }

    //Swaps all the digits around
    while(num > 0) {
        int remainder = num % 10;
        pali = pali * 10;
        pali = pali + remainder;
        num = num/10;
        count = count + 1;
    }

    for(int i = count; i > 1; i--) {
        int digit = pali % 10;
        pali = pali / 10;

        if(digit == 0) {
            continue;
        }
        printf("%d + ", digit*(int)pow(10, i-1));
    }
    printf("%d", pali);
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:");
    printf("10 + 2\n");
    printf("Actual  :");
    print_expanded_form(12);
    printf("\n");

    printf("Test 2\n");
    printf("Expected:");
    printf("100 + 20 + 3\n");
    printf("Actual  :");
    print_expanded_form(123);
    printf("\n");

    printf("Test 3\n");
    printf("Expected:");
    printf("100000 + 4\n");
    printf("Actual  :");
    print_expanded_form(100004);
    printf("\n");

    printf("Test 4\n");
    printf("Expected:");
    printf("Invalid Input!\n");
    printf("Actual  :");
    print_expanded_form(0);
    printf("\n");

    printf("Test 5\n");
    printf("Expected:");
    printf("Invalid Input!\n");
    printf("Actual  :");
    print_expanded_form(-163);
    printf("\n");

}