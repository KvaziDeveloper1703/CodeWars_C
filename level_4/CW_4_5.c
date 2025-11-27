/*
You must create a function getPINs that, given an observed PIN, returns all possible real PINs. Each digit in the observed PIN may actually be the digit itself or any horizontally or vertically adjacent digit on the keypad.

Keypad layout:
1 2 3
4 5 6
7 8 9
  0

For example, if the observed digit is 1, the actual digit could be 1, 2, or 4. If it is 5, it could be 2, 4, 5, 6, or 8. The observed PIN may have 1–8 digits.

Your function must return all combinations formed by replacing each digit with its possible real values. All PINs, including the input, must be strings, because leading zeros are allowed.

Нужно написать функцию getPINs, которая по наблюдаемому PIN-коду возвращает все возможные реальные PIN-коды. Каждая цифра в наблюдаемом PIN-е может быть самой собой или любой цифрой, расположенной к ней горизонтально или вертикально на клавиатуре.

Клавиатура:
1 2 3
4 5 6
7 8 9
  0

Например, если наблюдали цифру 1, она могла быть 1, 2 или 4. Если цифру 5, то это может быть 2, 4, 5, 6 или 8. Длина PIN-а - от 1 до 8 цифр.

Функция должна вернуть все возможные комбинации, подставляя к каждой цифре все её возможные реальные варианты. Входной и выходные PIN-коды должны быть строками, так как в них могут быть ведущие нули.
*/

#include <stdlib.h>
#include <string.h>

static const char* adjacencyList[10] = {
    "08",
    "124",
    "1235",
    "236",
    "1457",
    "24568",
    "3569",
    "478",
    "57890",
    "689"
};

static void generate_combinations(
        const char* observed,
        const char*** resultArray,
        size_t* resultCount,
        char* currentPin,
        size_t position,
        size_t totalLength
) {
    if (position == totalLength) {
        char* completedPin = malloc(totalLength + 1);
        memcpy(completedPin, currentPin, totalLength);
        completedPin[totalLength] = '\0';
        (*resultArray)[(*resultCount)++] = completedPin;
        return;
    }

    int digit = observed[position] - '0';
    const char* options = adjacencyList[digit];

    for (size_t i = 0; i < strlen(options); i++) {
        currentPin[position] = options[i];
        generate_combinations(observed, resultArray, resultCount,
                              currentPin, position + 1, totalLength);
    }
}

const char** get_pins(const char* observed, size_t* count) {
    size_t length = strlen(observed);
    size_t maxCombinations = 1;

    for (size_t i = 0; i < length; i++) {
        int digit = observed[i] - '0';
        maxCombinations *= strlen(adjacencyList[digit]);
    }

    const char** resultArray = malloc(sizeof(char*) * maxCombinations);
    char* currentPin = malloc(length + 1);

    *count = 0;

    generate_combinations(
            observed,
            &resultArray,
            count,
            currentPin,
            0,
            length
    );

    free(currentPin);
    return resultArray;
}

void free_pins(const char ** pins) {
    free((void*)pins);
}