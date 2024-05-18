/*
** EPITECH PROJECT, 2023
** my_put_short.c
** File description:
** Display short number.
*/

#include <stdarg.h>
#include "my.h"

static
int digit_count(int nb)
{
    int i = 0;

    if (nb < 0)
        i++;
    while (nb > 9) {
        i++;
        nb = nb / 10;
    }
    return i + 1;
}

int my_put_sh(short n)
{
    int total = digit_count(n);

    if (n < 0) {
        my_putchar('-');
        n = n * (- 1);
    }
    if (n <= 9)
        my_putchar(n + 48);
    if (n > 9) {
        my_put_nbr(n / 10);
        my_put_nbr(n % 10);
    }
    return total;
}
