/*
Given an array of integers, find the number that appears an odd number of times.

There will always be exactly one integer in the array that occurs an odd number of times.

Examples:
    - [7] → returns 7, because it appears 1 time;
    - [0] → returns 0, because it appears 1 time;
    - [1, 1, 2] → returns 2, because it appears 1 time.

Дан массив целых чисел. Нужно найти число, которое встречается нечётное количество раз.

Гарантируется, что в массиве есть ровно одно число, которое появляется нечётное число раз.

Примеры:
    - [7] → вернуть 7, потому что оно встречается 1 раз.
    - [0] → вернуть 0, потому что оно встречается 1 раз.
    - [1, 1, 2] → вернуть 2, потому что оно встречается 1 раз.
*/

#include <stddef.h>

int find_odd(size_t length, const int array[length])
{
    int xor_result = 0;

    for (size_t index = 0; index < length; index++) {
        xor_result ^= array[index];
    }

    return xor_result;
}