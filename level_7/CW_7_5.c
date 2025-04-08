/*
Write a function that takes any non-negative integer as an argument and returns it with its digits in descending order.

Examples:
Input: 42145
Output: 54421

Input: 145263
Output: 654321

Напишите функцию, которая принимает любое неотрицательное целое число и возвращает его цифры, расположенные в порядке убывания.

Примеры:
Ввод: 42145
Вывод: 54421

Ввод: 145263
Вывод: 654321

https://www.codewars.com/kata/5467e4d82edf8bbf40000155
*/

#include <stdio.h>
#include <stdlib.h>

int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int sort_digits_descending(int number) {
    int digit_array[10];
    int digit_count = 0;

    while (number > 0) {
        digit_array[digit_count++] = number % 10;
        number /= 10;
    }

    // Sort digits in descending order
    qsort(digit_array, digit_count, sizeof(int), compare_desc);

    int result = 0;
    for (int i = 0; i < digit_count; ++i) {
        result = result * 10 + digit_array[i];
    }

    return result;
}

int main() {
    int input;
    scanf("%d", &input);

    int sorted = sort_digits_descending(input);
    printf("%d\n", sorted);

    return 0;
}