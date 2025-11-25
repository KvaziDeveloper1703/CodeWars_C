/*
You are given a list of directions: "NORTH", "SOUTH", "EAST", "WEST".
Opposite directions cancel each other out:
    - NORTH ↔ SOUTH
    - EAST ↔ WEST

If two opposite directions appear next to each other, they represent unnecessary movement and should be removed.
After removing them, new pairs may become adjacent and should also be simplified.

Write a function dirReduc that takes an array of direction strings and returns a simplified version of the path, with all unnecessary opposite-direction pairs removed.

Examples:
Input: ["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]
Output: ["WEST"]

Вам дан список направлений: "NORTH", "SOUTH", "EAST", "WEST".
Противоположные направления взаимно уничтожают друг друга:
    - NORTH ↔ SOUTH
    - EAST ↔ WEST

Если два противоположных направления стоят рядом, то такое движение бессмысленно и должно быть удалено.
После удаления могут появиться новые пары, которые тоже нужно сократить.

Напишите функцию dirReduc, которая принимает массив строк-направлений и возвращает упрощённый путь без лишних шагов.

ПримерыЖ
Ввод: ["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]
Вывод: ["WEST"]
*/

#include <stdlib.h>
#include <string.h>

static int are_directions_opposite(const char *first_direction, const char *second_direction)
{
    return  (strcmp(first_direction, "NORTH") == 0 && strcmp(second_direction, "SOUTH") == 0) ||
            (strcmp(first_direction, "SOUTH") == 0 && strcmp(second_direction, "NORTH") == 0) ||
            (strcmp(first_direction, "EAST")  == 0 && strcmp(second_direction, "WEST")  == 0) ||
            (strcmp(first_direction, "WEST")  == 0 && strcmp(second_direction, "EAST")  == 0);
}

const char **dirReduc(const char *const input_directions[], int input_length, int *output_length)
{
    const char **directions_stack = malloc(input_length * sizeof(char *));
    int directions_stack_size = 0;

    for (int current_index = 0; current_index < input_length; current_index++) {
        const char *current_direction = input_directions[current_index];

        if (directions_stack_size > 0 &&
            are_directions_opposite(directions_stack[directions_stack_size - 1], current_direction)) {
            directions_stack_size--;
        } else {
            directions_stack[directions_stack_size++] = current_direction;
        }
    }

    *output_length = directions_stack_size;
    return directions_stack;
}