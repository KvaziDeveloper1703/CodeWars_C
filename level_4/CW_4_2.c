/*
Write a function that converts a non-negative number of seconds into a human-readable duration. If the input is 0, return "now". Otherwise, the result must use years, days, hours, minutes, and seconds, assuming that a year has 365 days and a day has 24 hours.

The output should use plural forms correctly, omit units with value 0, and place larger units before smaller ones. Components are separated by commas, except for the last one, which uses “and”. Durations must be expressed using the biggest possible units, so 61 seconds becomes “1 minute and 1 second”.

Examples:
62 → “1 minute and 2 seconds”
3662 → “1 hour, 1 minute and 2 seconds”

Нужно написать функцию, которая переводит неотрицательное число секунд в человеко-читаемую строку. Если секунд 0, вернуть "now". В остальных случаях длительность выражается в годах, днях, часах, минутах и секундах. Считаем, что в году 365 дней, а в дне 24 часа.

В выводе правильно используется множественное число, пропускаются нулевые единицы, и большие единицы идут раньше маленьких. Компоненты разделяются запятыми, а перед последним ставится “and”. Длительность должна быть приведена к максимально большим единицам, поэтому 61 секунда превращается в “1 minute and 1 second”.

Примеры:
62 → “1 minute and 2 seconds”
3662 → “1 hour, 1 minute and 2 seconds”
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *formatDuration(int totalSeconds) {
    if (totalSeconds == 0) {
        char *now = malloc(4);
        strcpy(now, "now");
        return now;
    }

    int years = totalSeconds / (365 * 24 * 3600);
    totalSeconds %= (365 * 24 * 3600);

    int days = totalSeconds / (24 * 3600);
    totalSeconds %= (24 * 3600);

    int hours = totalSeconds / 3600;
    totalSeconds %= 3600;

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    const char *namesSingular[] = {"year", "day", "hour", "minute", "second"};
    const char *namesPlural[]   = {"years", "days", "hours", "minutes", "seconds"};
    int values[] = {years, days, hours, minutes, seconds};

    char *parts[5];
    int partCount = 0;

    for (int i = 0; i < 5; i++) {
        if (values[i] == 0) {
            parts[i] = NULL;
            continue;
        }

        parts[i] = malloc(32);
        sprintf(parts[i], "%d %s", values[i],
                values[i] == 1 ? namesSingular[i] : namesPlural[i]);
        partCount++;
    }

    int maxLen = 128;
    char *result = malloc(maxLen);
    result[0] = '\0';

    int appended = 0;

    for (int i = 0; i < 5; i++) {
        if (!parts[i]) continue;

        appended++;

        strcat(result, parts[i]);

        if (appended < partCount - 1)
            strcat(result, ", ");
        else if (appended == partCount - 1)
            strcat(result, " and ");
    }

    for (int i = 0; i < 5; i++) {
        free(parts[i]);
    }

    return result;
}