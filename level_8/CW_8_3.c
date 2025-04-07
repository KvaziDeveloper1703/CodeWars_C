/*
You are given an array of numbers. Return the sum of all positive numbers in the array.

Вам дан массив чисел. Верните сумму всех положительных чисел в массиве.

https://www.codewars.com/kata/5715eaedb436cf5606000381
*/

#include <stdio.h>

int sum_of_positives(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int arr[] = {1, -4, 7, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Sum of positive numbers: %d\n", sum_of_positives(arr, size));
    
    return 0;
}