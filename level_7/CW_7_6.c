/*
You are going to be given a non-empty string. Your job is to return the middle character(s) of the string.
+ If the string's length is odd, return the middle character.
+ If the string's length is even, return the middle 2 characters.

Вам будет дана непустая строка. Ваша задача – вернуть средний символ(ы) этой строки.
+ Если длина строки нечетная, вернуть один средний символ.
+ Если длина строки четная, вернуть два средних символа.
*/

#include <stdio.h>
#include <string.h>

void get_middle(char *given_string, char *result) {
    size_t length = strlen(given_string);
    if (length % 2 == 0) {
        result[0] = given_string[length / 2 - 1];
        result[1] = given_string[length / 2];
        result[2] = '\0';
    } else {
        result[0] = given_string[length / 2];
        result[1] = '\0';
    }
}

int main() {
    char result[3];
    
    get_middle("test", result);
    printf("%s\n", result);
    
    return 0;
}