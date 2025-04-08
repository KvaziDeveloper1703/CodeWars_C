/*
Write a function that reverses the string passed into it.

Напишите функцию которая переворачивала бы переданную строку.

https://www.codewars.com/kata/5168bb5dfe9a00b126000018
*/

#include <stdio.h>
#include <string.h>

void reverse_string(char *given_string) {
    int length = strlen(given_string);
    for (int i = 0; i < length / 2; i++) {
        char temporary = given_string[i];
        given_string[i] = given_string[length - i - 1];
        given_string[length - i - 1] = temporary;
    }
}

int main() {
    char my_string[100];
    printf("Enter a string: ");
    scanf("%99s", my_string);
    
    reverse_string(my_string);
    printf("Reversed string: %s\n", my_string);
    
    return 0;
}