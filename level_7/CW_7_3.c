/*
You are asked to square every digit of a number and concatenate them.

Examples:
9119 → 811181
765 → 493625

В этом задании вам нужно возвести в квадрат каждую цифру числа и объединить их в одну строку.

Примеры:
9119 → 811181
765 → 493625
*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long square_digits(unsigned given_number) {
    unsigned long long result = 0;
    unsigned long long factor = 1;
    unsigned digits[10];
    int count = 0;
    
    if (given_number == 0) {
        return 0;
    }
    
    while (given_number > 0) {
        digits[count++] = given_number % 10;
        given_number /= 10;
    }
    
    for (int i = count - 1; i >= 0; i--) {
        unsigned squared = digits[i] * digits[i];
        
        if (squared >= 10) {
            result = result * 100 + squared;
        } else {
            result = result * 10 + squared;
        }
    }
    
    return result;
}

int main() {
    unsigned number;
    printf("Enter a number: ");
    scanf("%u", &number);
    
    unsigned long long result = square_digits(number);
    printf("Squared digits concatenated: %llu\n", result);
    
    return 0;
}