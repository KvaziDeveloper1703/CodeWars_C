/*
Write a function that removes the first and last characters of a given string.

Напишите функцию, которая удаляет первый и последний символы из переданной строки.

https://www.codewars.com/kata/56bc28ad5bdaeb48760009b0
*/

#include <stdio.h>
#include <string.h>

char* remove_char(char* given_processed_string, const char* given_original_string) {
    int length = strlen(given_original_string);

    if (length < 2) {
        given_processed_string[0] = '\0';
        return given_processed_string;
    }

    for (int i = 1; i < length - 1; i++) {
        given_processed_string[i - 1] = given_original_string[i];
    }

    given_processed_string[length - 2] = '\0';

    return given_processed_string;
}

int main() {
    char original_string[100];
    char processed_string[100];

    printf("Enter a string: ");
    scanf("%99s", original_string);

    remove_char(processed_string, original_string);

    printf("Modified string: %s\n", processed_string);

    return 0;
}