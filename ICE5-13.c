#include <stdio.h>


void print_calendar(int num_days, int first_sun) {
    int row = num_days/7 + 1;
    int day = 1;

    printf("Su Mo Tu We Th Fr Sa\n");

    if(first_sun != 1) { //Without this IF statement, an empty line appears when first Sunday is 1
        //First Row
        //identifies number of spaces
        for(int j = 0; j <= (7 - (first_sun-1)) * 3; j++) {
            printf(" ");
        }
        //inputs the numbers before first Sunday
        for(int j = (20 - (first_sun-1)); j < 20; j++) {
            printf("%d  ", day);
            day = day + 1;
        }
        printf("\n");

    }

    //Subsequent Rows
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < 7; j++) {
            if(day < 10) {
                printf(" ");
            }
            if(day <= num_days) {
                printf("%d ", day);
                day = day + 1;
            } else {
                break;
            }
        }
        printf("\n");
    }
}

int main(void) {
    //days_of_week(1, 2, 1897);

    print_calendar(30, 2);
    printf("\n");
    print_calendar(31, 1);
    printf("\n");
    print_calendar(31, 7);
}