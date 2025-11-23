/*
The digital root of a number is obtained by repeatedly summing its digits until only one digit remains.

Given a non-negative integer n, sum all of its digits.
If the result has more than one digit, repeat the process until you get a single-digit number.
Return that final value.

Examples:
16 → 1 + 6 = 7
942 → 9 + 4 + 2 = 15 → 1 + 5 = 6
132189 → 24 → 2 + 4 = 6
493193 → 29 → 2 + 9 = 11 → 1 + 1 = 2

Цифровой корень числа получается путём повторного суммирования всех цифр, пока не останется одна цифра.

Дано неотрицательное число n. Сложите все его цифры.
Если результат содержит более одной цифры, повторяйте процесс, пока не получите однозначное число.
Верните это значение.

Примеры:
16 → 1 + 6 = 7
942 → 9 + 4 + 2 = 15 → 1 + 5 = 6
132189 → 24 → 2 + 4 = 6
493193 → 29 → 2 + 9 = 11 → 1 + 1 = 2
*/

int digital_root(int number) {
    while (number >= 10) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        number = sum;
    }
    return number;
}