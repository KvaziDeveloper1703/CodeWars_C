/*
Create a function that increments a string and returns the updated version.
If the string ends with a number, increase that number by 1.
If the string has no number at the end, append 1 to it.
If the ending number contains leading zeros, keep the same number of digits when possible.

Examples:
foo → foo1
foobar23 → foobar24
foo0042 → foo0043
foo9 → foo10

Создайте функцию, которая увеличивает строку и возвращает её обновлённый вариант.
Если строка заканчивается числом, это число нужно увеличить на 1.
Если строка не заканчивается числом, в конец нужно добавить 1.
Если в конце строки есть число с ведущими нулями, важно сохранить количество цифр, когда это возможно.

Примеры:
foo → foo1
foobar23 → foobar24
foo0042 → foo0043
foo9 → foo10
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *incrementString(const char *input_string)
{
    if (input_string == NULL) {
        return NULL;
    }

    size_t input_length = strlen(input_string);

    size_t number_start_index = input_length;

    while (number_start_index > 0 &&
           isdigit((unsigned char)input_string[number_start_index - 1]))
    {
        number_start_index--;
    }

    size_t prefix_length = number_start_index;
    size_t number_length = input_length - number_start_index;

    char *prefix_string = malloc(prefix_length + 1);
    if (!prefix_string) return NULL;
    memcpy(prefix_string, input_string, prefix_length);
    prefix_string[prefix_length] = '\0';

    if (number_length == 0) {
        char *result_string = malloc(prefix_length + 2);
        if (!result_string) return NULL;

        memcpy(result_string, prefix_string, prefix_length);
        result_string[prefix_length] = '1';
        result_string[prefix_length + 1] = '\0';

        free(prefix_string);
        return result_string;
    }

    char *number_string = malloc(number_length + 1);
    if (!number_string) return NULL;
    memcpy(number_string, input_string + number_start_index, number_length);
    number_string[number_length] = '\0';

    unsigned long long number_value = strtoull(number_string, NULL, 10);
    number_value++;

    char incremented_number_buffer[64];
    snprintf(incremented_number_buffer, sizeof(incremented_number_buffer), "%llu", number_value);

    size_t incremented_number_length = strlen(incremented_number_buffer);

    size_t zeros_to_prepend = 0;
    if (incremented_number_length < number_length) {
        zeros_to_prepend = number_length - incremented_number_length;
    }

    size_t result_length = prefix_length + number_length + 1;

    char *result_string = malloc(result_length);
    if (!result_string) return NULL;

    memcpy(result_string, prefix_string, prefix_length);

    for (size_t i = 0; i < zeros_to_prepend; i++) {
        result_string[prefix_length + i] = '0';
    }

    memcpy(result_string + prefix_length + zeros_to_prepend,
           incremented_number_buffer,
           incremented_number_length);

    result_string[prefix_length + zeros_to_prepend + incremented_number_length] = '\0';

    free(prefix_string);
    free(number_string);

    return result_string;
}