/*
You need to create a function that takes a number and return its opposite.

Вам необходимо создать функцию, которая принимает число и возвращает его противоположность.

https://www.codewars.com/kata/56dec885c54a926dcd001095
*/

#include <stdio.h>

double opposite(double given_number) {
    return -given_number;
}

int main() {
    double number;

    printf("Enter a number: ");
    scanf("%lf", &number);

    printf("The opposite number is: %.2lf\n", opposite(number));

    return 0;
}