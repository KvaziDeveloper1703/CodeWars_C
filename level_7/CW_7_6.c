/*
You are going to be given a non-empty string. Your job is to return the middle character(s) of the string.
+ If the string's length is odd, return the middle character.
+ If the string's length is even, return the middle 2 characters.

Вам будет дана непустая строка. Ваша задача – вернуть средний символ(ы) этой строки.
+ Если длина строки нечетная, вернуть один средний символ.
+ Если длина строки четная, вернуть два средних символа.

https://www.codewars.com/kata/56747fd5cb988479af000028
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_middle(const char *input_string) {
    size_t input_length = strlen(input_string);
    char *middle_characters = malloc((input_length % 2 == 0 ? 3 : 2));
    if (!middle_characters) return NULL;

    if (input_length % 2 == 0) {
        middle_characters[0] = input_string[input_length / 2 - 1];
        middle_characters[1] = input_string[input_length / 2];
        middle_characters[2] = '\0';
    } else {
        middle_characters[0] = input_string[input_length / 2];
        middle_characters[1] = '\0';
    }

    return middle_characters;
}

int main() {
    char *middle_result = get_middle("test");
    if (middle_result) {
        printf("%s\n", middle_result);
        free(middle_result);
    }
    return 0;
}