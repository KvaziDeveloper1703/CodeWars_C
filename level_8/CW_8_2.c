/*
In this simple task, you are given a number and need to make it negative. However, if the number is already negative, leave it unchanged.

В этом простом задании вам дано число, и его нужно сделать отрицательным. Однако, если число уже отрицательное, оставьте его без изменений.
*/

#include <stdio.h>

int make_negative(int given_number) {
    return (given_number > 0) ? -given_number : given_number;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("Negative version: %d\n", make_negative(number));
    
    return 0;
}
