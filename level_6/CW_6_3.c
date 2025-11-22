/*
You probably know the “like” system from Facebook and similar platforms. People can “like” posts, pictures, or other items. We want to generate the text that should appear next to such an item.

Implement a function that takes an array of names of people who like an item. It must return a display string according to the following rules:
    - [] → "no one likes this";
    - ["Peter"] → "Peter likes this";
    - ["Jacob", "Alex"] → "Jacob and Alex like this";
    - ["Max", "John", Mark"] → "Max, John and Mark like this";
    - ["Alex", "Jacob", "Mark", "Max"] → "Alex, Jacob and 2 others like this".

The function must return a newly allocated string. Do not modify the input array.

Вы наверняка знаете систему «лайков» из Facebook и других сайтов. Люди могут «лайкать» посты, картинки и другие элементы. Нужно сформировать текст, который отображается рядом с таким элементом.

Реализуйте функцию, которая принимает массив имён людей, поставивших лайк. Она должна вернуть строку по следующим правилам:
    - [] → "no one likes this";
    - ["Peter"] → "Peter likes this";
    - ["Jacob", "Alex"] → "Jacob and Alex like this";
    - ["Max", "John", "Mark"] → "Max, John and Mark like this";
    - ["Alex", "Jacob", "Mark", "Max"] → "Alex, Jacob and 2 others like this".

Функция должна возвращать новую строку. Не изменяйте входной массив.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *likes(size_t n, const char *const names[n]) {
    char *result = NULL;

    if (n == 0) {
        result = malloc(strlen("no one likes this") + 1);
        strcpy(result, "no one likes this");
    } 
    else if (n == 1) {
        size_t size = strlen(names[0]) + strlen(" likes this") + 1;
        result = malloc(size);
        sprintf(result, "%s likes this", names[0]);
    } 
    else if (n == 2) {
        size_t size = strlen(names[0]) + strlen(names[1]) +
                      strlen(" and  like this") + 1;
        result = malloc(size);
        sprintf(result, "%s and %s like this", names[0], names[1]);
    } 
    else if (n == 3) {
        size_t size = strlen(names[0]) + strlen(names[1]) + strlen(names[2]) +
                      strlen(",  and  like this") + 1;
        result = malloc(size);
        sprintf(result, "%s, %s and %s like this",
                names[0], names[1], names[2]);
    } 
    else {
        size_t others = n - 2;
        char buffer[32];
        sprintf(buffer, "%zu", others);
        size_t size =
            strlen(names[0]) + strlen(names[1]) +
            strlen(buffer) + strlen(",  and  others like this") + 1;
        result = malloc(size);
        sprintf(result, "%s, %s and %zu others like this",
                names[0], names[1], others);
    }

    return result;
}