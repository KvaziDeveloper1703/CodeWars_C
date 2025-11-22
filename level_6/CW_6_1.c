/*
If we list all natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, and 9. The sum of these numbers is 23.

Finish the function so that it returns the sum of all multiples of 3 or 5 below the given number.

If the number is negative, return 0.

Если перечислить все натуральные числа меньше 10, которые являются кратными 3 или 5, получим 3, 5, 6 и 9. Их сумма равна 23.

Допишите функцию так, чтобы она возвращала сумму всех чисел, кратных 3 или 5, которые меньше переданного числа.

Если число отрицательное - вернуть 0.
*/

int solution(int number) {
    if (number < 0) return 0;

    int sum = 0;

    for (int i = 1; i < number; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}