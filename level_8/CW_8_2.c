/*
You are given a number and need to make it negative. However, if the number is already negative, leave it unchanged.

Вам дано число, и его нужно сделать отрицательным. Однако, если число уже отрицательное, оставьте его без изменений.

https://www.codewars.com/kata/55685cd7ad70877c23000102
*/

#include <stdio.h>

int make_negative(int given_number) {
    if (given_number > 0) {
        return -given_number;
    } else {
        return given_number;
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("Negative number: %d\n", make_negative(number));
    
    return 0;
}