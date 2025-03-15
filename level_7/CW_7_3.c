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
#include <string.h>

int square_digits(int given_number) {
    char buffer[50] = "";
    char temporary[10];
    
    int reversed = 0;
    int original = given_number;
    while (given_number > 0) {
        reversed = reversed * 10 + given_number % 10;
        given_number /= 10;
    }
    
    while (reversed > 0 || original == 0) {
        int digit = reversed % 10;
        sprintf(temporary, "%d", digit * digit);
        strcat(buffer, temporary);
        reversed /= 10;
        original = -1;
    }
    
    return atoi(buffer);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    int result = square_digits(number);
    printf("Squared digits concatenated: %d\n", result);
    
    return 0;
}