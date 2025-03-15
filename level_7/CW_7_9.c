/*
An isogram is a word that has no repeating letters, consecutive or non-consecutive.

Write a function that checks whether a given string is an isogram.
+ Ignore letter case.
+ The empty string is considered an isogram.

Изограмма – это слово, в котором нет повторяющихся букв, ни подряд, ни вразброс.

Напишите функцию, которая проверяет, является ли переданная строка изограммой.
+ Регистр букв игнорируется.
+ Пустая строка считается изограммой.
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
    printf("%d\n", is_isogram("aba"));
    printf("%d\n", is_isogram("moOse"));
    printf("%d\n", is_isogram(""));
    return 0;
}