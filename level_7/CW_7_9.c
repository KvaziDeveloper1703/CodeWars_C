/*
An isogram is a word that has no repeating letters.

You need to create a function that checks whether a given string is an isogram.
+ Ignore letter case;
+ The empty string is considered an isogram.

Изограмма – это слово, в котором нет повторяющихся букв.

Вам нужно написать функцию, которая проверяет, является ли переданная строка изограммой.
+ Регистр букв игнорируется;
+ Пустая строка считается изограммой.

https://www.codewars.com/kata/54ba84be607a92aa900000f1
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_isogram(const char *given_string) {
    bool letters[26] = {false};

    while (*given_string) {
        if (isalpha(*given_string)) {
            char lower = tolower(*given_string);
            int index = lower - 'a';
            if (letters[index]) {
                return false;
            }
            letters[index] = true;
        }
        given_string++;
    }
    return true;
}

int main() {
    printf("%d\n", is_isogram("background"));
    printf("%d\n", is_isogram("lamp"));
    printf("%d\n", is_isogram("letter"));
    printf("%d\n", is_isogram("Alphabet"));
    printf("%d\n", is_isogram("Hello"));
    return 0;
}