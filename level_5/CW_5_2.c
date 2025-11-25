/*
Write a function that takes a non-negative integer representing a number of seconds and returns a human-readable time string in the format HH:MM:SS.
    - HH - hours, padded to 2 digits, range 00–99;
    - MM - minutes, padded to 2 digits, range 00–59;
    - SS - seconds, padded to 2 digits, range 00–59.

The input will never exceed 359999 seconds, which corresponds to 99:59:59.

Напишите функцию, которая принимает неотрицательное целое число — количество секунд, — и возвращает строку в читаемом формате времени HH:MM:SS.
    - HH - часы, дополненные ведущим нулём, диапазон 00–99;
    - MM - минуты, дополненные ведущим нулём, диапазон 00–59;
    - SS - секунды, дополненные ведущим нулём, диапазон 00–59.

Значение входа никогда не превышает 359999 секунд.
*/

#include <stdio.h>

char *human_readable_time(unsigned seconds, char *time_string)
{
    unsigned hours = seconds / 3600;
    unsigned minutes = (seconds % 3600) / 60;
    unsigned remaining_seconds = seconds % 60;

    sprintf(time_string, "%02u:%02u:%02u", hours, minutes, remaining_seconds);
    return time_string;
}