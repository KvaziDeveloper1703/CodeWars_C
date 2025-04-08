/*
Write a function that checks whether a given integer is a perfect square.

Напишите функцию, которая проверяет, является ли заданное целое число идеальным квадратом.

https://www.codewars.com/kata/54c27a33fb7da0db0100040e
*/

#include <stdbool.h>
#include <math.h>

bool is_square(int given_number) {
    if (given_number < 0) return false;
    
    int sqrt_number = (int)sqrt(given_number);
    return sqrt_number * sqrt_number == given_number;
}

int main() {
    printf("%d\n", is_square(0));
    printf("%d\n", is_square(16));
    printf("%d\n", is_square(15));
    printf("%d\n", is_square(-9));
    printf("%d\n", is_square(123));
    return 0;
}