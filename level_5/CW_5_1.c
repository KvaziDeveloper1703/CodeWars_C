/*
Write a function move_zeros(n, array) that takes an integer n and an integer array.
The function should move all zeros to the end of the array, while preserving the order of all non-zero elements.

Example:
move_zeros(10, int[] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1});
Output:int[] {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}

Напишите функцию move_zeros(n, array), которая принимает число n и массив целых чисел.
Функция должна переместить все нули в конец массива, при этом сохранив порядок всех ненулевых элементов.

Пример:
move_zeros(10, int[] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1});
Результат: int[] {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}
*/

#include <stddef.h>

void move_zeros(size_t length, int array[length])
{
    size_t next_non_zero_position = 0;

    for (size_t current_index = 0; current_index < length; current_index++) {
        if (array[current_index] != 0) {
            array[next_non_zero_position++] = array[current_index];
        }
    }

    while (next_non_zero_position < length) {
        array[next_non_zero_position++] = 0;
    }
}