/*
Complete the function so that it reverses the string passed into it.

Дополните функцию так, чтобы она переворачивала переданную строку.
*/

#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temporary = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temporary;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);
    
    reverse_string(str);
    printf("Reversed string: %s\n", str);
    
    return 0;
}