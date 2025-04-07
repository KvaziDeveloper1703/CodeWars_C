/*
You are given an array of numbers. Return the sum of all positive numbers in the array.

Вам дан массив чисел. Верните сумму всех положительных чисел в массиве.

https://www.codewars.com/kata/5715eaedb436cf5606000381
*/

#include <stdio.h>

int sum_of_positives(int given_array[], int given_size) {
    int sum = 0;
    for (int i = 0; i < given_size; i++) {
        if (given_array[i] > 0) {
            sum += given_array[i];
        }
    }
    return sum;
}

int main() {
    int array[] = {1, -4, 7, 12};
    int size = sizeof(array) / sizeof(array[0]);
    
    printf("Sum of positive numbers: %d\n", sum_of_positives(array, size));
    
    return 0;
}