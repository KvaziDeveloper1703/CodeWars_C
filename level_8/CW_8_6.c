/*
Write a function that takes a boolean value and returns:
+ "Yes" if the value is true;
+ "No" if the value is false.

Напишите функцию, которая принимает логическое значение и возвращает:
+ "Yes", если значение true;
+ "No", если значение false.

https://www.codewars.com/kata/53369039d7ab3ac506000467
*/

#include <stdio.h>

const char *bool_to_word(int given_boolean_value) {
    if (given_boolean_value) {
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