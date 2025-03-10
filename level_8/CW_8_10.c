/*
Write a function that takes a non-negative integer n and a string s as parameters. It should return a new string where s is repeated exactly n times.

Напишите функцию, которая принимает неотрицательное целое число n и строку s в качестве параметров. Функция должна вернуть новую строку, где s повторяется ровно n раз.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat_str(int n, const char* s) {
    int length = strlen(s) * n;
    char* result = (char*) malloc(length + 1);

    if (result == NULL) {
        return NULL;
    }

    char* ptr = result;
    for (int i = 0; i < n; i++) {
        strcpy(ptr, s);
        ptr += strlen(s);
    }

    *ptr = '\0';
    
    return result;
}

int main() {
    int n;
    char s[100];

    printf("Enter a string: ");
    scanf("%99s", s);
    
    printf("Enter repetition count: ");
    scanf("%d", &n);

    char* repeated = repeat_str(n, s);

    if (repeated) {
        printf("Repeated string: %s\n", repeated);
        free(repeated);
    } else {
        printf("Memory allocation failed.\n");
    }
    
    return 0;
}