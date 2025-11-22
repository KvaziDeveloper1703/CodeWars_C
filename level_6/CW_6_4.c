/*
Implement a function that computes the difference between two lists.
The function should remove from the first list (a) all elements that also appear in the second list (b).
All occurrences must be removed, and the order of the remaining elements in a must be preserved.

Examples:
    - If a = [1, 2] and b = [1], the result is [2].
    - If a = [1, 2, 2, 2, 3] and b = [2], the result is [1, 3].

Реализуйте функцию, которая вычисляет разность двух списков.
Функция должна удалить из первого списка (a) все элементы, которые присутствуют во втором списке (b).
Удаляются все вхождения, и порядок оставшихся элементов в a должен сохраниться.

Примеры:
    - Если a = [1, 2] и b = [1], результат - [2].
    - Если a = [1, 2, 2, 2, 3] и b = [2], результат - [1, 3].
*/

#include <stddef.h>
#include <stdlib.h>

int *array_diff(const int first_array[], size_t first_array_length,
                const int second_array[], size_t second_array_length,
                size_t *result_length)
{
    int *result_array = malloc(first_array_length * sizeof(int));
    size_t result_array_length = 0;

    for (size_t index_first_array = 0; index_first_array < first_array_length; index_first_array++) {
        int should_remove_current_element = 0;

        for (size_t index_second_array = 0; index_second_array < second_array_length; index_second_array++) {
            if (first_array[index_first_array] == second_array[index_second_array]) {
                should_remove_current_element = 1;
                break;
            }
        }

        if (!should_remove_current_element) {
            result_array[result_array_length++] = first_array[index_first_array];
        }
    }

    *result_length = result_array_length;
    return result_array;
}