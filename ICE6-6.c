#include <stdio.h>
#include <math.h>

void print_pascal(int n) {
    int array[n][n];    //I admit it wastes memory from all the unused elements but yeah the other way was to do it all in a 1 dimensional array
                            //and that is quite a lot of logic to work out manually.

    //Just initialises the first 2 rows to allow the rest to be calculated.
    array[0][0] = 1;
    array[1][0] = 1;
    array[1][1] = 1;
    printf("%d \n", array[0][0]);
    printf("%d ", array[1][0]);
    printf("%d \n", array[1][1]);

    //I ended up using 2D arrays, cool to know 2D arrays in C work similar to other languages :D
    for(int row = 2; row < n; row++) {
        array[row][0] = 1;
        printf("%d ", array[row][0] = 1);

        for(int column = 1; column < row; column++) {
            array[row][column] = array[row-1][column-1] + array[row-1][column];
            printf("%d ", array[row][column]);
        }
        array[row][row] = 1;
        printf("%d \n", array[row][row]);
    }
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:\n");
    printf("1 \n");
    printf("1 1\n"); 
    printf("1 2 1\n");
    printf("1 3 3 1\n");
    printf("1 4 6 4 1\n");
    printf("Actual:\n");
    print_pascal(5);
    printf("\n");
    
    printf("Test 2\n");
    printf("Expected:\n");
    printf("1\n");
    printf("1 1\n"); 
    printf("1 2 1\n"); 
    printf("1 3 3 1\n");
    printf("1 4 6 4 1\n");
    printf("1 5 10 10 5 1\n");
    printf("1 6 15 20 15 6 1\n");
    printf("1 7 21 35 35 21 7 1\n");
    printf("1 8 28 56 70 56 28 8 1\n");
    printf("1 9 36 84 126 126 84 36 9 1\n");
    printf("Actual:\n");
    print_pascal(10);
}
