/*
Create a function that removes the first and last characters of a given string.

Создайте функцию, которая удаляет первый и последний символы из переданной строки.
*/

#include <stdio.h>
#include <string.h>

char* remove_char(char* dst, const char* src) {
    int length = strlen(src);

    if (length < 2) {
        dst[0] = '\0';
        return dst;
    }

    for (int i = 1; i < length - 1; i++) {
        dst[i - 1] = src[i];
    }

    dst[length - 2] = '\0';
    
    return dst;
}

int main() {
    char src[100];
    char dst[100];

    printf("Enter a string: ");
    scanf("%99s", src);

    remove_char(dst, src);

    printf("Modified string: %s\n", dst);
    
    return 0;
}