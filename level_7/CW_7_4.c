/*
In this little assignment, you are given a string of space-separated numbers and have to return the highest and lowest number.

В этом небольшом задании вам дана строка, содержащая числа, разделенные пробелами. Вам нужно вернуть наибольшее и наименьшее число.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void high_and_low(const char *given_numbers, char *result) {
    int max = INT_MIN, min = INT_MAX;
    int number;
    const char *ptr = given_numbers;

    while (*ptr) {
        if (sscanf(ptr, "%d", &number) == 1) {
            if (number > max) max = number;
            if (number < min) min = number;
        }
        while (*ptr && *ptr != ' ') ptr++;
        while (*ptr == ' ') ptr++;
    }

    sprintf(result, "%d %d", max, min);
}

int main() {
    char result[50];
    high_and_low("1 2 3 4 5", result);
    printf("%s\n", result);
    
    return 0;
}