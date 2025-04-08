/*
Write a function that squares each number in the given list and returns the sum of these squared values.

Напишите функцию, которая возводит в квадрат каждое число из переданного списка и возвращает сумму этих квадратов.

https://www.codewars.com/kata/515e271a311df0350d00000f
*/

#include <stdio.h>

int square_sum(int given_numbers[], int given_size) {
    int sum = 0;

    for (int i = 0; i < given_size; i++) {
        sum += given_numbers[i] * given_numbers[i];
    }

    return sum;
}

int main() {
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int numbers[size];

    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Sum of squares: %d\n", square_sum(numbers, size));
    
    return 0;
}