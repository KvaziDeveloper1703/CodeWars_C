/*
Write a function that takes a non-negative integer N and a string S as parameters. It should return a new string where S is repeated exactly N times.

Напишите функцию, которая принимает неотрицательное целое число N и строку S в качестве параметров. Функция должна вернуть новую строку, где S повторяется ровно N раз.

https://www.codewars.com/kata/56dec885c54a926dcd001095
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat_string(int given_N, const char* given_S) {
    // Calculate the total length needed for the repeated string
    int length = strlen(given_S) * given_N;

    // Dynamically allocate memory for the result string (+1 for the null terminator)
    char* result = malloc(length + 1);

    // Check if memory allocation was successful
    if (result == NULL) {
        return NULL;
    }

    // Use a pointer to fill the allocated memory with repeated copies of the string
    char* pointer = result;
    for (int i = 0; i < given_N; i++) {
        strcpy(pointer, given_S);
        pointer += strlen(given_S);  // Move the pointer forward after each copy
    }

    // Add the null terminator at the end of the string
    *pointer = '\0';

    // Return the pointer to the beginning of the allocated string
    return result;
}

int main() {
    int N;
    char S[100];

    printf("Enter a string: ");
    scanf("%99s", S);
    
    printf("Enter repetition count: ");
    scanf("%d", &N);

    // Call the function that returns a dynamically allocated string
    char* repeated = repeat_string(N, S);

    // If allocation succeeded, print and then free the memory
    if (repeated) {
        printf("Repeated string: %s\n", repeated);
        free(repeated);  // Free the dynamically allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }
    
    return 0;
}