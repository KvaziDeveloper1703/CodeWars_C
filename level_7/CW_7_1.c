/*
Write a function that returns the number (count) of vowels in the given string.

We will consider a, e, i, o, u as vowels for this Kata (but not y).

The input string will only consist of lowercase letters and/or spaces.

Напишите функцию, которая возвращает количество (счет) гласных букв в заданной строке.

Мы будем считать гласными только a, e, i, o, u (но не y).

Входная строка будет содержать только строчные буквы и/или пробелы.
*/

#include <stdio.h>

int count_vowels(const char *given_string) {
    int count = 0;
    while (*given_string) {
        switch (*given_string) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
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