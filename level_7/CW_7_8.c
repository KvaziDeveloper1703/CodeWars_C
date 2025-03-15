/*
Write a function accum that transforms a string as follows:
Each letter is repeated as many times as its position in the string (starting from 1),
the first letter is uppercase, the rest are lowercase.
Parts are separated by "-".

Examples:
accum("abcd") → "A-Bb-Ccc-Dddd"
accum("RqaEzty") → "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"

Напишите функцию accum, которая преобразует строку следующим образом:
Каждая буква повторяется столько раз, каково её положение в строке (начиная с 1), первый символ в верхнем регистре, остальные в нижнем.
Части разделяются "-".

Примеры:
accum("abcd") → "A-Bb-Ccc-Dddd"
accum("RqaEzty") → "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* accum(const char *given_string) {
    size_t length = strlen(given_string);
    size_t result_size = length * (length + 1) / 2 + length;
    char *result = (char*)malloc(result_size * sizeof(char));
    if (!result) return NULL;
    
    size_t pos = 0;
    for (size_t i = 0; i < length; i++) {
        result[pos++] = toupper(given_string[i]);
        for (size_t j = 0; j < i; j++) {
            result[pos++] = tolower(given_string[i]);
        }
        if (i < length - 1) {
            result[pos++] = '-';
        }
    }
    result[pos] = '\0';
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