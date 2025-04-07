/*
You need to create a function that takes an integer as an argument and returns "Even" if the number is even or "Odd" if the number is odd.

Вам нужно создать функцию, которая принимает целое число в качестве аргумента и возвращает "Even", если число чётное, или "Odd", если число нечётное.

https://www.codewars.com/kata/53da3dbb4a5168369a0000fe
*/

#include <stdio.h>

const char* even_or_odd(int given_number) {
    if (given_number % 2 == 0)
        return "Even";
    else
        return "Odd";
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    
    printf("The number is: %s\n", even_or_odd(number));
    
    return 0;
}