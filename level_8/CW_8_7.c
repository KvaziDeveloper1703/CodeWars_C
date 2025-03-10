/*
Complete the square_sum function so that it squares each number in the given list and returns the sum of these squared values.

Дополните функцию square_sum, чтобы она возводила в квадрат каждое число из переданного списка и возвращала сумму этих квадратов.
*/

#include <stdio.h>

int square_sum(int numbers[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += numbers[i] * numbers[i];
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