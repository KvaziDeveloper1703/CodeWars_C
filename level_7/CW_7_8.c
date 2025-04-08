/*
You need to create a function that transforms a string as follows:
Each letter is repeated as many times as its position in the string, the first letter is uppercase, the rest are lowercase.
Parts are separated by "-".

Examples:
Input: "abcd"
Output: "A-Bb-Ccc-Dddd"

Input: "RqaEzty"
Output: "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"

Вам нужно написать функцию, которая преобразует строку следующим образом:
Каждая буква повторяется столько раз, каково её положение в строке, первый символ в верхнем регистре, остальные в нижнем.
Части разделяются "-".

Примеры:
Ввод: "abcd"
Вывод: "A-Bb-Ccc-Dddd"

Ввод: "RqaEzty"
Вывод: "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"

https://www.codewars.com/kata/5667e8f4e3f572a8f2000039
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* accum(const char *given_string) {
    size_t length = strlen(given_string);
    size_t result_size = length * (length + 1) / 2 + length;
    char *result = malloc(result_size * sizeof(char));
    if (!result) return NULL;
    
    size_t position = 0;
    for (size_t i = 0; i < length; i++) {
        result[position++] = toupper(given_string[i]);
        for (size_t j = 0; j < i; j++) {
            result[position++] = tolower(given_string[i]);
        }
        if (i < length - 1) {
            result[position++] = '-';
        }
    }
    result[position] = '\0';
    return result;
}

int main() {
    char *result;
    
    result = accum("abcd");
    printf("%s\n", result);
    free(result);
    
    result = accum("RqaEzty");
    printf("%s\n", result);
    free(result);
    
    return 0;
}