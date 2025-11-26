/*
John and I are members of the “Fat to Fit Club”. Every month a list of members’ weights is published, and John is always last because he is the heaviest. To help him, we decide to reorder the list by assigning a “weight” to each number, defined as the sum of its digits. For example, 99 has a weight of 18, and 100 has a weight of 1, so 100 should appear before 99.

Given a string containing members’ weights separated by spaces, return the string sorted according to the digit sums of the numbers. If two numbers have the same digit sum, sort them alphabetically as strings rather than numerically. All numbers are positive, and the list may be empty.

Example:
Input: "56 65 74 100 99 68 86 180 90"
Output: "100 180 90 56 65 74 68 86 99"

Мы с Джоном состоим в клубе “Fat to Fit Club”. Каждый месяц публикуется список весов участников, и Джон всегда оказывается последним, потому что он самый тяжелый. Чтобы помочь ему, мы решили менять порядок списка, назначая каждому числу новый “вес” - сумму его цифр. Например, у 99 “вес” равен 18, у 100 - 1, поэтому 100 должно идти раньше 99.

Дана строка с весами участников, разделёнными пробелами. Нужно вернуть эту строку, отсортированную по сумме цифр чисел. Если у двух чисел сумма цифр одинаковая, сортировать их нужно как строки в алфавитном порядке, а не как числа. Все числа положительные, список может быть пустым.

Пример:
Ввод: "56 65 74 100 99 68 86 180 90"
Вывод: "100 180 90 56 65 74 68 86 99"
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *number_string;
    int digit_sum;
} NumberEntry;

int compute_digit_sum(const char *number_string) {
    int sum = 0;
    for (size_t index = 0; number_string[index] != '\0'; index++) {
        if (isdigit((unsigned char)number_string[index])) {
            sum += number_string[index] - '0';
        }
    }
    return sum;
}

int compare_entries(const void *a, const void *b) {
    const NumberEntry *entry_a = (const NumberEntry *)a;
    const NumberEntry *entry_b = (const NumberEntry *)b;

    if (entry_a->digit_sum < entry_b->digit_sum) return -1;
    if (entry_a->digit_sum > entry_b->digit_sum) return 1;

    return strcmp(entry_a->number_string, entry_b->number_string);
}

char *orderWeight(const char *string)
{
    if (string == NULL || *string == '\0') {
        char *empty_result = malloc(1);
        if (empty_result) empty_result[0] = '\0';
        return empty_result;
    }

    char *string_copy = strdup(string);
    if (!string_copy) return NULL;

    size_t number_count = 0;
    char *token = strtok(string_copy, " ");
    while (token) {
        number_count++;
        token = strtok(NULL, " ");
    }

    free(string_copy);

    string_copy = strdup(string);
    if (!string_copy) return NULL;

    NumberEntry *entries = malloc(number_count * sizeof(NumberEntry));
    if (!entries) {
        free(string_copy);
        return NULL;
    }

    size_t index = 0;
    token = strtok(string_copy, " ");
    while (token) {
        entries[index].number_string = strdup(token);
        entries[index].digit_sum = compute_digit_sum(token);
        index++;
        token = strtok(NULL, " ");
    }

    qsort(entries, number_count, sizeof(NumberEntry), compare_entries);

    size_t result_length = 0;
    for (size_t i = 0; i < number_count; i++) {
        result_length += strlen(entries[i].number_string) + 1;
    }

    char *result_string = malloc(result_length + 1);
    if (!result_string) return NULL;

    result_string[0] = '\0';

    for (size_t i = 0; i < number_count; i++) {
        strcat(result_string, entries[i].number_string);
        if (i + 1 < number_count) strcat(result_string, " ");
    }

    for (size_t i = 0; i < number_count; i++) {
        free(entries[i].number_string);
    }

    free(entries);
    free(string_copy);

    return result_string;
}