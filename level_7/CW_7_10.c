/*
Write a function that checks if a string has the same number of 'x' and 'o'.
+ Case insensitive;
+ The string may contain any characters;
+ If no 'x' or 'o' are present, return true.

Напишите функцию, которая проверяет, содержит ли строка одинаковое количество символов 'x' и 'o'.
+ Регистр не учитывается;
+ Строка может содержать любые символы;
+ Если в строке нет 'x' и 'o', вернуть true.

https://www.codewars.com/kata/55908aad6620c066bc00002a
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool XO(const char *given_string) {
    int count_x = 0, count_o = 0;
    
    while (*given_string) {
        char character = tolower(*given_string);
        if (character == 'x') count_x++;
        if (character == 'o') count_o++;
        given_string++;
    }
    
    return count_x == count_o;
}

int main() {
    printf("%d\n", XO("ooxx"));
    printf("%d\n", XO("xooxx"));
    printf("%d\n", XO("ooxXm"));
    printf("%d\n", XO("zpzpzpp"));
    return 0;
}