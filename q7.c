#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_array(int row, int column, char arr[row][column]);

void print_dancing_string(char *string, char ch) {
    char arr[3][strlen(string)+2];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < strlen(string)+2; j++) {
            if(j == 0 || j == strlen(string)+1) {
                arr[i][j] = '|';
            } else {
                arr[i][j] = ' ';
            }
        }
    }

    int row = 0;
    if(ch == 'M') {
        row = 1;
    } else if (ch == 'B') {
        row = 2;
    }

    bool up = true;
    int column = 1;
    
    for(int i = 0; i < strlen(string); i++) {
        arr[row][column] = string[i];

        if(row == 0) {
            row++;
            up = false;
        } else if (row == 1 && up == true) {
            row--;
        } else if (row == 1 && up == false) {
            row++;
        } else if (row == 2) {
            row--;
            up = true;
        }
        column++;
    }
    print_array(3, strlen(string)+2, arr);
}

void print_array(int row, int column, char arr[row][column]) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:\n");
        printf("|a|\n");
        printf("| |\n");
        printf("| |\n");
        printf("Actual  :\n");
        print_dancing_string("a", 'T');
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:\n");
        printf("|a   e   i|\n");
        printf("| b d f h |\n");
        printf("|  c   g  |\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'T');
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:\n");
        printf("| b   f   |\n");
        printf("|a c e g i|\n");
        printf("|   d   h |\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'M');
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:\n");
        printf("|  c   g  |\n");
        printf("| b d f h |\n");
        printf("|a   e   i|\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'B');
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:\n");
        printf("||\n");
        printf("||\n");
        printf("||\n");
        printf("Actual  :\n");
        print_dancing_string("", 'B');
        printf("\n");
    }
}