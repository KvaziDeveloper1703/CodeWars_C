/*
You are given an array of integers.
The array consists entirely of either even numbers or odd numbers, except for one number N that differs in parity.
Write a function that takes this array and returns the outlier N.

Examples:
[2, 4, 0, 100, 4, 11, 2602, 36] → 11
[160, 3, 1719, 19, 11, 13, -21] → 160

Дан массив целых чисел.
Массив полностью состоит либо из чётных чисел, либо из нечётных, за исключением одного числа N, которое отличается по чётности.
Напишите функцию, которая принимает массив и возвращает это выбивающееся число N.

Примеры:
[2, 4, 0, 100, 4, 11, 2602, 36] → 11
[160, 3, 1719, 19, 11, 13, -21] → 160
*/

#include <stddef.h>

int find_outlier(const int values[], size_t count)
{
    int even_count = 0;
    int odd_count = 0;

    for (size_t i = 0; i < 3; i++) {
        if (values[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }

    int find_even = (odd_count > even_count);

    for (size_t i = 0; i < count; i++) {
        if (find_even) {
            if (values[i] % 2 == 0)
                return values[i];
        } else {
            if (values[i] % 2 != 0)
                return values[i];
        }
    }

    return 0;
}