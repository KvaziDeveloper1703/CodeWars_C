/*
ROT13 is a simple substitution cipher that replaces each letter with the letter 13 positions later in the alphabet. It is a variant of the Caesar cipher.
Create a function that takes a string and returns it encoded with ROT13.
If the string contains numbers or special characters, they must remain unchanged.
Only letters of the Latin/English alphabet should be shifted, exactly as in the original ROT13 implementation.

ROT13 - это простой шифр подстановки, который заменяет каждую букву на букву, находящуюся на 13 позиций дальше в алфавите. Он является вариантом шифра Цезаря.
Создайте функцию, которая принимает строку и возвращает строку, зашифрованную с помощью ROT13.
Если в строке есть цифры или специальные символы, они должны остаться без изменений.
Сдвиг применяется только к буквам латинского/английского алфавита, как в оригинальной реализации ROT13.
*/

#include <stdlib.h>

char *rot13(const char *input_string)
{
    if (input_string == NULL) {
        return NULL;
    }

    size_t input_length = 0;
    while (input_string[input_length] != '\0') {
        input_length++;
    }

    char *rot13_result_string = malloc(input_length + 1);
    if (rot13_result_string == NULL) {
        return NULL;
    }

    for (size_t index = 0; index < input_length; index++)
    {
        char current_character = input_string[index];

        if (current_character >= 'A' && current_character <= 'Z') {
            rot13_result_string[index] =
                ((current_character - 'A' + 13) % 26) + 'A';
        }
        else if (current_character >= 'a' && current_character <= 'z') {
            rot13_result_string[index] =
                ((current_character - 'a' + 13) % 26) + 'a';
        }
        else {
            rot13_result_string[index] = current_character;
        }
    }

    rot13_result_string[input_length] = '\0';

    return rot13_result_string;
}