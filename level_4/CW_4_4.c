/*
Create a function that takes a positive integer and returns the next larger number that can be formed by rearranging its digits. If no larger number can be created, return -1.

Examples:
12 → 21
513 → 531

Cases with no bigger permutation:
9 → -1
111 → -1

Создайте функцию, которая принимает положительное число и возвращает следующее большее число, которое можно составить из тех же цифр. Если получить большее число невозможно, нужно вернуть -1.

Примеры:
12 → 21
513 → 531

Ситуации, когда большего числа нет:
9 → -1
111 → -1
*/

#include <stdlib.h>

long long next_bigger_number(long long number) {
    int digitArray[20];
    int digitCount = 0;
    long long temporaryNumber = number;

    while (temporaryNumber > 0) {
        digitArray[digitCount++] = temporaryNumber % 10;
        temporaryNumber /= 10;
    }

    if (digitCount == 0) return -1;

    for (int index = 0; index < digitCount / 2; index++) {
        int temporaryDigit = digitArray[index];
        digitArray[index] = digitArray[digitCount - 1 - index];
        digitArray[digitCount - 1 - index] = temporaryDigit;
    }

    int pivotIndex = -1;
    for (int index = digitCount - 2; index >= 0; index--) {
        if (digitArray[index] < digitArray[index + 1]) {
            pivotIndex = index;
            break;
        }
    }

    if (pivotIndex == -1) return -1;

    int swapPositionIndex = pivotIndex + 1;
    for (int index = pivotIndex + 1; index < digitCount; index++) {
        if (digitArray[index] > digitArray[pivotIndex] &&
            digitArray[index] < digitArray[swapPositionIndex]) {
            swapPositionIndex = index;
        }
    }

    {
        int temporaryDigit = digitArray[pivotIndex];
        digitArray[pivotIndex] = digitArray[swapPositionIndex];
        digitArray[swapPositionIndex] = temporaryDigit;
    }

    for (int indexI = pivotIndex + 1; indexI < digitCount - 1; indexI++) {
        for (int indexJ = indexI + 1; indexJ < digitCount; indexJ++) {
            if (digitArray[indexI] > digitArray[indexJ]) {
                int temporaryDigit = digitArray[indexI];
                digitArray[indexI] = digitArray[indexJ];
                digitArray[indexJ] = temporaryDigit;
            }
        }
    }

    long long resultNumber = 0;
    for (int index = 0; index < digitCount; index++) {
        resultNumber = resultNumber * 10 + digitArray[index];
    }

    return resultNumber;
}