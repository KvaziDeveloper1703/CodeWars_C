/*
We need a function that converts an integer into a string.

Нужно написать функцию, которая преобразует целое число в строку.
*/

#include <stdio.h>
#include <stdlib.h>

char *number_to_string(int given_number) {
    char *str = malloc(12);

    if (str == NULL) {
        return NULL;
    }

    sprintf(str, "%d", given_number);
    return str;
}

int main() {
    int number;
    
    printf("Введите целое число: ");
    scanf("%d", &number);
    
    char *str = number_to_string(number);
    
    if (str != NULL) {
        printf("Число в виде строки: %s\n", str);
        free(str);
    } else {
        printf("Ошибка: не удалось выделить память.\n");
    }
    
    return 0;
}