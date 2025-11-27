/*
Given an n × n 2-dimensional array, return its elements arranged from the outer layer toward the center, moving in a clockwise spiral.

Example:
array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) ➝ [1,2,3,6,9,8,7,4,5]

Another example for clarity:
array = [[1,2,3],
         [8,9,4],
         [7,6,5]]

snail(array) ➝ [1,2,3,4,5,6,7,8,9]

Дан двумерный массив размера n × n. Нужно вернуть все его элементы, двигаясь по спирали с внешнего слоя к центру, по часовой стрелке.

Пример:
array = [[1,2,3],
         [4,5,6],
         [7,8,9]]

snail(array) ➝ [1,2,3,6,9,8,7,4,5]

Другой пример:
array = [[1,2,3],
         [8,9,4],
         [7,6,5]]

snail(array) ➝ [1,2,3,4,5,6,7,8,9]
*/

#include <stdlib.h>

int *snail(size_t *outputSize, const int **matrix, size_t numberOfRows, size_t numberOfColumns) {
    if (numberOfRows == 0 || numberOfColumns == 0) {
        *outputSize = 0;
        return NULL;
    }

    size_t totalElementCount = numberOfRows * numberOfColumns;
    int *resultArray = malloc(totalElementCount * sizeof(int));
    if (!resultArray) {
        *outputSize = 0;
        return NULL;
    }

    size_t currentIndex = 0;
    size_t topRow = 0;
    size_t bottomRow = numberOfRows - 1;
    size_t leftColumn = 0;
    size_t rightColumn = numberOfColumns - 1;

    while (topRow <= bottomRow && leftColumn <= rightColumn) {
        for (size_t columnIndex = leftColumn; columnIndex <= rightColumn; columnIndex++)
            resultArray[currentIndex++] = matrix[topRow][columnIndex];
        topRow++;

        if (topRow > bottomRow) break;

        for (size_t rowIndex = topRow; rowIndex <= bottomRow; rowIndex++)
            resultArray[currentIndex++] = matrix[rowIndex][rightColumn];
        rightColumn--;

        if (leftColumn > rightColumn) break;

        for (size_t columnIndex = rightColumn; columnIndex >= leftColumn; columnIndex--) {
            resultArray[currentIndex++] = matrix[bottomRow][columnIndex];
            if (columnIndex == leftColumn) break;
        }
        bottomRow--;

        if (topRow > bottomRow) break;

        for (size_t rowIndex = bottomRow; rowIndex >= topRow; rowIndex--) {
            resultArray[currentIndex++] = matrix[rowIndex][leftColumn];
            if (rowIndex == topRow) break;
        }
        leftColumn++;
    }

    *outputSize = currentIndex;
    return resultArray;
}