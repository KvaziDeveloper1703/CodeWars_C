/*
Write a function that takes an array of 10 integers and returns a string formatted as a phone number.

The output must follow this exact format: (123) 456-7890

Make sure to include the space after the closing parenthesis.

Example:
create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});

Напишите функцию, которая принимает массив из 10 целых чисел и возвращает строку, отформатированную как номер телефона.

Формат результата должен быть строго таким: (123) 456-7890

Не забудьте поставить пробел после закрывающей скобки.

Пример:
create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});
*/

#include <stdint.h>

char *create_phone_number(char phnum[15], const uint8_t digits[10])
{
    phnum[0]  = '(';
    phnum[1]  = digits[0] + '0';
    phnum[2]  = digits[1] + '0';
    phnum[3]  = digits[2] + '0';
    phnum[4]  = ')';
    phnum[5]  = ' ';
    phnum[6]  = digits[3] + '0';
    phnum[7]  = digits[4] + '0';
    phnum[8]  = digits[5] + '0';
    phnum[9]  = '-';
    phnum[10] = digits[6] + '0';
    phnum[11] = digits[7] + '0';
    phnum[12] = digits[8] + '0';
    phnum[13] = digits[9] + '0';
    phnum[14] = '\0';

    return phnum;
}