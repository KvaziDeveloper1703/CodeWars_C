/*
Complete the rgb function. It should take three decimal RGB values and return their hexadecimal color representation.
    - Valid RGB values are in the range 0–255;
    - Any value outside this range must be clamped to the nearest valid value;
    - The returned hexadecimal string must always contain exactly 6 characters.

Examples:
255, 255, 255 → "FFFFFF"
255, 255, 300 → "FFFFFF"
0, 0, 0 → "000000"
148, 0, 211 → "9400D3"

Допишите функцию rgb. Она должна принимать три десятичных значения RGB и возвращать их шестнадцатеричное представление цвета.
    - Допустимый диапазон значений: 0–255;
    - Любое значение вне диапазона нужно привести к ближайшему корректному;
    - Возвращаемая строка в формате hex должна содержать ровно 6 символов.

Примеры:
255, 255, 255 → "FFFFFF"
255, 255, 300 → "FFFFFF"
0, 0, 0 → "000000"
148, 0, 211 → "9400D3"
*/

#include <stdio.h>

static int clamp(int value)
{
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

void rgb(int r, int g, int b, char hex[6 + 1])
{
    r = clamp(r);
    g = clamp(g);
    b = clamp(b);

    sprintf(hex, "%02X%02X%02X", r, g, b);
}