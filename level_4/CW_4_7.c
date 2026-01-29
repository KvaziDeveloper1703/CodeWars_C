/*
A function mystery(n) is defined for non negative integers. Let n be represented using m bits. A table T(m) is defined recursively. T(1) equals [0, 1]. T(m + 1) is obtained by taking T(m), appending its reversed copy, prefixing the first half with 0 and the second half with 1. The value mystery(n) is the number whose binary representation equals T(m)[n] with indexing starting from 0.
For example T(3) equals [000, 001, 011, 010, 110, 111, 101, 100], so mystery(6) equals 101 in binary which is 5 in decimal.
You must implement mystery(n), its inverse mystery_inv(n) and a function name_of_mystery() that returns the common name of this function. The argument n may contain up to 63 bits and generating T(m) explicitly is not allowed.

Функция mystery(n) определена для неотрицательных целых чисел. Пусть число n представлено m битами. Таблица T(m) задается рекурсивно. T(1) равно [0, 1]. T(m + 1) получается из T(m) путем приписывания к ней развернутой копии, при этом к первой половине добавляется префикс 0, а ко второй префикс 1. Значение mystery(n) это число, двоичное представление которого равно T(m)[n] при индексации с нуля.
Например T(3) равно [000, 001, 011, 010, 110, 111, 101, 100], поэтому mystery(6) равно 101 в двоичном виде что соответствует числу 5.
Требуется реализовать функции mystery(n), обратную функцию mystery_inv(n) и функцию name_of_mystery() возвращающую общепринятое название данной функции. Число n может содержать до 63 бит и явное построение таблицы T(m) запрещено.
*/

unsigned long long mystery(unsigned long long n) {
    return n ^ (n >> 1);
}

unsigned long long mystery_inv(unsigned long long n) {
    unsigned long long result = 0;
    while (n) {
        result ^= n;
        n >>= 1;
    }
    return result;
}

const char* name_of_mystery(void) {
    return "Gray code";
}