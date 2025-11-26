/*
Fibonacci numbers form the sequence 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... where F(0)=0, F(1)=1 and each next number is the sum of the previous two.

Given a number prod, you must find two consecutive Fibonacci numbers F(n) and F(n+1) such that F(n) * F(n+1) = prod.
If such a pair exists, return (F(n), F(n+1), True).
If not, return (F(n), F(n+1), False), where these are the first consecutive Fibonacci numbers whose product becomes greater than prod.

Example:
714 → (21, 34, True);
800 → (34, 55, False).

Числа Фибоначчи - это последовательность 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... где F(0)=0, F(1)=1, а каждое следующее число равно сумме двух предыдущих.

Дано число prod. Нужно найти два соседних числа Фибоначчи F(n) и F(n+1), для которых F(n) * F(n+1) = prod.
Если такие есть, вернуть (F(n), F(n+1), True).
Если нет, вернуть (F(n), F(n+1), False), где это первые числа Фибоначчи, произведение которых становится больше prod.

Примеры:
714 → (21, 34, True);
800 → (34, 55, False).
*/

#include <stdlib.h>

typedef unsigned long long ull;

ull *productFib(ull prod)
{
    ull *result_array = malloc(3 * sizeof(ull));
    if (result_array == NULL) {
        return NULL;
    }

    ull fibonacci_previous = 0;
    ull fibonacci_current = 1;

    while (fibonacci_previous * fibonacci_current < prod)
    {
        ull fibonacci_next = fibonacci_previous + fibonacci_current;
        fibonacci_previous = fibonacci_current;
        fibonacci_current = fibonacci_next;
    }

    result_array[0] = fibonacci_previous;
    result_array[1] = fibonacci_current;

    if (fibonacci_previous * fibonacci_current == prod) {
        result_array[2] = 1;    
    } else {
        result_array[2] = 0;
    }

    return result_array;
}