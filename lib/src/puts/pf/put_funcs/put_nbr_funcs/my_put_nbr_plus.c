/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Display a number.
*/

#include <stdarg.h>
#include "my.h"

int my_put_nbr_plus(int n)
{
    int total = my_digit_count(n);

    if (n < 0) {
        my_putchar('-');
        n = n * (- 1);
    } else
        my_putchar('+');
    if (n <= 9)
        my_putchar(n + 48);
    if (n > 9) {
        my_put_nbr(n / 10);
        my_put_nbr(n % 10);
    }
    return total;
}
