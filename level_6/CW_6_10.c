/*
Write a function that returns the number of distinct characters in a string that appear more than once.
Characters should be compared case-insensitively, and the string contains only alphabetic characters and digits.

Examples:
"abcde" → 0
"aabbcde" → 2
"indivisibility" → 1

Напишите функцию, которая возвращает количество различных символов в строке, которые встречаются более одного раза.
Сравнение должно быть регистронезависимым, а строка содержит только буквы и цифры.

Примеры:
"abcde" → 0
"aabbcde" → 2
"indivisibility" → 1
*/

#include <stddef.h>
#include <ctype.h>

size_t duplicate_count(const char *text) {
    int character_frequencies[36] = {0};
    size_t number_of_characters_with_duplicates = 0;
    const char *text_pointer = text;

    while (*text_pointer) {
        char current_character = (char)tolower((unsigned char)*text_pointer);

        if (current_character >= '0' && current_character <= '9') {
            int index_in_frequency_array = current_character - '0';
            if (character_frequencies[index_in_frequency_array] == 1) {
                number_of_characters_with_duplicates++;
            }
            character_frequencies[index_in_frequency_array]++;
        } else if (current_character >= 'a' && current_character <= 'z') {
            int index_in_frequency_array = 10 + (current_character - 'a');
            if (character_frequencies[index_in_frequency_array] == 1) {
                number_of_characters_with_duplicates++;
            }
            character_frequencies[index_in_frequency_array]++;
        }

        text_pointer++;
    }

    return number_of_characters_with_duplicates;
}