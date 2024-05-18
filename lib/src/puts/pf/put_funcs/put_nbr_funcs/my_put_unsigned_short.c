/*
** EPITECH PROJECT, 2023
** my_put_unsigned_short.c
** File description:
** Display unsigned short number.
*/

#include <stdarg.h>
#include "my.h"

static
int my_unsigned_short_count(unsigned short nb)
{
    int i = 0;

    while (nb > 9) {
        i++;
        nb = nb / 10;
    }
    return i + 1;
}

int my_put_unsigned_short(unsigned short n)
{
    int total = my_unsigned_short_count(n);

    if (n <= 9)
        my_putchar(n + 48);
    if (n > 9) {
        my_put_nbr(n / 10);
        my_put_nbr(n % 10);
    }
    return total;
}
