/*
You need to implement a function that takes a sorted list of integers and returns a string where consecutive numbers are grouped. Single numbers are written normally, while sequences of at least three consecutive integers are written as a range using a dash. A range includes both endpoints. Sequences of only two numbers are not written as a range.

Example:
Input: [-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20]
Output: "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"

Нужно написать функцию, которая принимает отсортированный список целых чисел и возвращает строку, в которой подряд идущие числа объединяются. Отдельные числа записываются как есть, а последовательности из минимум трёх подряд идущих чисел записываются в виде диапазона через дефис. Диапазон включает оба конца. Последовательности из двух чисел не считаются диапазоном.

Пример:
Ввод: [-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20]
Вывод: "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *range_extraction(const int *args, size_t n)
{
    if (n == 0) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char *result = malloc(1024);
    result[0] = '\0';

    size_t i = 0;
    while (i < n) {
        size_t start = i;
        size_t end = i;

        while (end + 1 < n && args[end + 1] == args[end] + 1)
            end++;

        if (end - start >= 2) {
            char buffer[64];
            sprintf(buffer, "%d-%d", args[start], args[end]);
            strcat(result, buffer);
        } else if (end - start == 1) {
            char buffer[64];
            sprintf(buffer, "%d,%d", args[start], args[end]);
            strcat(result, buffer);
        } else {
            char buffer[32];
            sprintf(buffer, "%d", args[start]);
            strcat(result, buffer);
        }

        i = end + 1;
        if (i < n) strcat(result, ",");
    }

    return result;
}