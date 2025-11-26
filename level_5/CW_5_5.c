/*
The maximum sum subarray problem requires finding the largest possible sum of a contiguous subsequence in a list of integers.

Example:
Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6

Задача о максимальной сумме подмассива состоит в том, чтобы найти наибольшую возможную сумму непрерывной подпоследовательности в списке целых чисел.

Пример:
Вход: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Выход: 6
*/

#include <stddef.h>

int max_sequence(const int array[], size_t length)
{
    int current_subarray_sum = 0;
    int maximum_subarray_sum = 0;

    for (size_t current_index = 0; current_index < length; current_index++) {
        current_subarray_sum += array[current_index];

        if (current_subarray_sum < 0) {
            current_subarray_sum = 0;
        }

        if (current_subarray_sum > maximum_subarray_sum) {
            maximum_subarray_sum = current_subarray_sum;
        }
    }

    return maximum_subarray_sum;
}