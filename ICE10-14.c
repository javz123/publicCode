#include <stdio.h>
#include <string.h>

void longest_common_suffix(char *s1, char *s2, char *s3) {
    char *s1dup = s1;
    char *s2dup = s2;
    while(*s1 != '\0' || *s2 != '\0') {
        if(*s1 != '\0') {
            s1++;
        }
        if(*s2 != '\0') {
            s2++;
        }
    }
    s1--; //move the pointer from \0 to the char before it
    s2--;

    while(s1 != s1dup && s2 != s2dup) {
        if(*s1 == *s2) {
            s1--;
            s2--;
            continue;
        } else {
            s1++;
            break;
        }
    }

    while (*s1 != '\0') {
        *s3 = *s1;
        s1++;
        s3++;
    }
    *s3 = '\0';
}

int main(void) {
    {
        char *s1 = "incident";
        char *s2 = "accident";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 1\n");
        printf("Expected:cident\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "crocodile";
        char *s2 = "horse";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 2\n");
        printf("Expected:e\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "eat";
        char *s2 = "treat";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 3\n");
        printf("Expected:eat\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "discontent";
        char *s2 = "discontinue";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 4\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", s3);
        printf("\n");
    }
}