/*
Given a number (integer or decimal), return its opposite (additive inverse).

Дано число (целое или десятичное). Верните его противоположное (аддитивный инверс).
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