/*
Complete the function that takes a boolean value and returns:
+ "Yes" if the value is True.
+ "No" if the value is False.

Дополните функцию, которая принимает логическое значение и возвращает:
+ "Yes", если значение True.
+ "No", если значение False.
*/

#include <stdio.h>

const char *bool_to_word(int boolean_value) {
    if (boolean_value) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    int value;

    printf("Enter 1 (true) or 0 (false): ");
    scanf("%d", &value);

    printf("Result: %s\n", bool_to_string(value));
    
    return 0;
}

