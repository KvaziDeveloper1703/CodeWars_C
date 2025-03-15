/*
Your task is to write a function that takes a string and returns a new string with all vowels removed.

Example:
"This website is for losers LOL!" -> "Ths wbst s fr lsrs LL!"

Ваша задача – написать функцию, которая принимает строку и возвращает новую строку, из которой удалены все гласные.

Пример:
"This website is for losers LOL!" -> "Ths wbst s fr lsrs LL!"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *disemvowel(const char *given_string)
{
	int length = strlen(given_string);
    char *result = (char *)malloc(length + 1);
    if (!result) return NULL;
    
    int j = 0;
    for (int i = 0; i < length; i++) {
        switch (given_string[i]) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                break;
            default:
                result[j++] = given_string[i];
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    char *output = disemvowel(input);
    printf("String without vowels: %s\n", output);
    
    free(output);
    return 0;
}