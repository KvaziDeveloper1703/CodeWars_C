/*
Write a function that converts an integer into a string.

Напишите функцию, которая преобразует целое число в строку.

https://www.codewars.com/kata/5265326f5fda8eb1160004c8
*/

#include <stdio.h>
#include <stdlib.h>  // Required for malloc() and free()

// Converts an integer to a dynamically allocated string
char *number_to_string(int given_number) {
    // Allocate 12 bytes of memory to hold the string version of the number
    // This size is enough for a 32-bit signed integer: "-2147483648" + '\0'
    char *string = malloc(12);

    // Check if malloc failed
    if (string == NULL) {
        return NULL;  // Return NULL to indicate failure
    }

    // Use sprintf to convert the integer to a string
    sprintf(string, "%d", given_number);

    // Return the pointer to the newly created string
    return string;
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    char *string = number_to_string(number);

    // Check if memory allocation was successful
    if (string != NULL) {
        printf("Number as a string: %s\n", string);

        // Free the dynamically allocated memory to avoid memory leaks
        free(string);
    } else {
        // Handle memory allocation failure
        printf("Error: could not allocate memory.\n");
    }

    return 0;
}