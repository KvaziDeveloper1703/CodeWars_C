/*
Your task is to write a function that takes any non-negative integer as an argument and returns it with its digits in descending order.
Essentially, rearrange the digits to create the highest possible number.

Ваша задача – написать функцию, которая принимает любое неотрицательное целое число и возвращает его цифры, расположенные в порядке убывания.
Проще говоря, нужно переставить цифры так, чтобы получилось наибольшее возможное число.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *number_1, const void *number_2) {
    return (*(char *)number_2 - *(char *)number_1);
}

long long descending_order(long long given_number) {
    char string[20];
    sprintf(string, "%lld", given_number);
    
    size_t length = strlen(string);
    qsort(string, length, sizeof(char), compare);
    
    return atoll(string);
}

int main() {
    printf("%lld\n", descending_order(123456789));
    return 0;
}