/*
You are given a string of space-separated numbers and have to return the highest and lowest number.

Вам дана строка, содержащая числа, разделенные пробелами. Вам нужно вернуть наибольшее и наименьшее число.

https://www.codewars.com/kata/554b4ac871d6813a03000035
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void high_and_low(const char *given_numbers, char *result) {
    // INT_MIN and INT_MAX are the smallest and largest possible values for an int.
    // They help initialize min and max to extreme values for proper comparison.
    int max = INT_MIN, min = INT_MAX;

    // strdup creates a duplicate of the input string because strtok modifies it.
    // The original string is marked as const, so we work with a modifiable copy.
    char *numbers = strdup(given_numbers);

    // strtok splits the string into tokens separated by spaces.
    // It returns a pointer to the first token, or NULL if there are none.
    char *token = strtok(numbers, " ");

    while (token) {
        int number = atoi(token);
        if (number > max) max = number;
        if (number < min) min = number;

        // strtok(NULL, " ") continues tokenizing from where it left off.
        token = strtok(NULL, " ");
    }

    sprintf(result, "%d %d", max, min);

    // Free the duplicated string to avoid memory leaks.
    free(numbers);
}

int main() {
    char result[50];
    high_and_low("1 2 3 4 5", result);
    printf("%s\n", result);
    
    return 0;
}