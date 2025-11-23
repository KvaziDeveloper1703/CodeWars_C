/*
Write a function that takes a non-negative integer and returns the number of bits set to 1 in its binary representation.

Example:
The number 1234 in binary is 10011010010, so the function should return 5.

Напишите функцию, которая принимает неотрицательное целое число и возвращает количество битов, равных 1, в его двоичном представлении.

Пример:
Число 1234 в двоичном виде - 10011010010, поэтому функция должна вернуть 5.
*/

#include <stddef.h>

size_t countBits(unsigned value)
{
    size_t count = 0;
    while (value) {
        count += value & 1;
        value >>= 1;
    }
    return count;
}