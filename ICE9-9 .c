#include <stdio.h>
#include <stdbool.h>

char * my_strstr(char *haystack, char *needle) {
    if(*needle == '\0') { //Edge case
        return haystack;
    }

    char *ptr = NULL;
    char *tempNeedle = needle;

    while (*haystack != '\0') {
        if(*haystack == *needle) {
            ptr = haystack;
            while(*needle != '\0') {
                if(*haystack == *needle) {
                    needle++;
                    haystack++;
                } else if(*haystack == '\0') {
                    return NULL;
                } else {
                    ptr = NULL;
                    needle = tempNeedle;
                    break;
                }
            }
        }
        haystack++;
    }
    return ptr;
}

int main(void) {
    {
        char *haystack = "this is a simple string";
        char *needle = "simple";
        printf("Test 1\n");
        printf("Expected:simple string\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "this is a simple string";
        char *needle = "";
        printf("Test 2\n");
        printf("Expected:this is a simple string\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "C is a wonderful language";
        char *needle = "Python";
        printf("Test 3\n");
        printf("Expected:(null)\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and oranges";
        char *needle = "apple";
        printf("Test 4\n");
        printf("Expected:apples and oranges\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and oranges";
        char *needle = "orange";
        printf("Test 5\n");
        printf("Expected:oranges\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and orange";
        char *needle = "orangest";
        printf("Test 6\n");
        printf("Expected:(null)\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

}