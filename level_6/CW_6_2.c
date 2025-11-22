'''
Write a function that takes a string containing one or more words and returns the same string, but with all words that have five or more letters reversed.
The input string will contain only letters and spaces. Spaces appear only when there is more than one word.

Examples:
    - "Hey fellow warriors" → "Hey wollef sroirraw"
    - "This is a test" → "This is a test"
    - "This is another test" → "This is rehtona test"

Напишите функцию, которая принимает строку из одного или нескольких слов и возвращает ту же строку, но со всеми словами длиной пять символов и больше, записанными в обратном порядке.
Входная строка содержит только буквы и пробелы. Пробелы присутствуют только если слов больше одного.

Примеры:
    - "Hey fellow warriors" → "Hey wollef sroirraw"
    - "This is a test" → "This is a test"
    - "This is another test" → "This is rehtona test"
'''

#include <string.h>

void spin_words(const char *sentence, char *result) {
    int i = 0, r = 0, start = 0;
    int len = strlen(sentence);

    while (i <= len) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            int word_len = i - start;

            if (word_len >= 5) {
                for (int k = i - 1; k >= start; k--) {
                    result[r++] = sentence[k];
                }
            } else {
                for (int k = start; k < i; k++) {
                    result[r++] = sentence[k];
                }
            }

            if (sentence[i] == ' ')
                result[r++] = ' ';

            start = i + 1;
        }
        i++;
    }

    result[r] = '\0';
}