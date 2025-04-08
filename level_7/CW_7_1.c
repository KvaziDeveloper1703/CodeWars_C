/*
Write a function that returns the number of vowels in the given string.
The input string will only consist of lowercase letters and/or spaces.

Напишите функцию, которая возвращает количество гласных букв в заданной строке.
Входная строка будет содержать только строчные буквы и/или пробелы.

https://www.codewars.com/kata/54ff3102c1bad923760001f3
*/

#include <stdio.h>

int count_vowels(const char *given_string) {
    int count = 0;
    while (*given_string) {
        switch (*given_string) {
            case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
                count++;
                break;
        }
        given_string++;
    }
    return count;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    printf("Number of vowels: %d\n", count_vowels(input));
    return 0;
}