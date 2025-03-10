/*
Write a function that takes a non-negative integer n and a string s as parameters. It should return a new string where s is repeated exactly n times.

Напишите функцию, которая принимает неотрицательное целое число n и строку s в качестве параметров. Функция должна вернуть новую строку, где s повторяется ровно n раз.
*/

#include <iostream>
#include <string>
#include <cstring>

std::string repeat_str(int n, const std::string& s) {
    std::string result;
    for (int i = 0; i < n; i++) {
        result += s;
    }
    return result;
}

int main() {
    int n;
    std::string s;

    std::cout << "Enter a string: ";
    std::cin >> s;

    std::cout << "Enter repetition count: ";
    std::cin >> n;

    std::cout << "Repeated string: " << repeat_str(n, s) << std::endl;

    return 0;
}