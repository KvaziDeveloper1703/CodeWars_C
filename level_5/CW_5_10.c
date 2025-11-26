/*
Write a function scramble(str1, str2) that returns True if the characters in str2 can be formed by rearranging some of the characters from str1. Otherwise, return False.
Only lowercase letters (a–z) are used, with no digits or punctuation.
Performance matters, and both input strings are null-terminated.

Examples:
scramble('rkqodlw', 'world') → True
scramble('cedewaraaossoqqyt', 'codewars') → True
scramble('katas', 'steak') → False

Напишите функцию scramble(str1, str2), которая возвращает True, если из символов строки str1 можно составить строку str2, переставляя буквы. Если это невозможно - вернуть False.
Используются только строчные буквы латинского алфавита (a–z), без цифр и знаков препинания.
Важно учитывать производительность. Обе строки оканчиваются нулевым символом.

Примеры:
scramble('rkqodlw', 'world') → True
scramble('cedewaraaossoqqyt', 'codewars') → True
scramble('katas', 'steak') → False
*/

#include <stdbool.h>
#include <stddef.h>

bool scramble(const char *source_string, const char *target_string)
{
    int letter_frequency_table[26] = {0};

    for (size_t source_index = 0; source_string[source_index] != '\0'; source_index++) {
        char current_source_character = source_string[source_index];
        int alphabet_position = current_source_character - 'a';
        letter_frequency_table[alphabet_position]++;
    }

    for (size_t target_index = 0; target_string[target_index] != '\0'; target_index++) {
        char current_target_character = target_string[target_index];
        int alphabet_position = current_target_character - 'a';

        if (letter_frequency_table[alphabet_position] == 0) {
            return false;
        }

        letter_frequency_table[alphabet_position]--;
    }

    return true;
}