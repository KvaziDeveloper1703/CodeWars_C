/*
You are given an array X of positive integers.

You may repeatedly apply the following operation to the elements of the array:
    - Choose two indices i and j;
    - If X[i] > X[j], replace X[i] = X[i] - X[j].

You can perform this operation any number of times and in any order.

When no more operations are possible, all elements of the array will be equal.
Return the sum of the array in this final state.

Constraints:
    - The array can contain up to 30,000 elements;
    - Values can be very large;
    - Your solution must be efficient to avoid timeouts.

Example:
Input: X = [6, 9, 21]
Output: 9

Дан массив X, состоящий из положительных целых чисел.

К элементам массива можно многократно применять следующую операцию:
    - Выбрать два индекса i и j;
    - Если X[i] > X[j], заменить X[i] = X[i] - X[j].

Операцию можно выполнять любое количество раз и в любом порядке.

Когда дальнейшие преобразования становятся невозможны, все элементы массива будут равны.
Необходимо вернуть сумму элементов массива в этом конечном состоянии.

Ограничения:
    - Размер массива - до 30 000 элементов;
    - Значения элементов могут быть очень большими;
    - Требуется эффективный алгоритм, чтобы избежать превышения лимита времени.

Пример:
Ввод: X = [6, 9, 21]
Вывод: 9
*/

#include <stddef.h>

static int greatest_common_divisor(int first_value, int second_value) {
    while (second_value) {
        int temporary_value = second_value;
        second_value = first_value % second_value;
        first_value = temporary_value;
    }
    return first_value;
}

int smallest_possible_sum(size_t array_size, const int array[array_size]) {
    if (array_size == 0) return 0;

    int common_divisor = array[0];
    for (size_t index = 1; index < array_size; index++) {
        common_divisor = greatest_common_divisor(common_divisor, array[index]);
    }

    return common_divisor * (int)array_size;
}