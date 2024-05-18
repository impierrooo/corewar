/*
** EPITECH PROJECT, 2023
** my_put_unsigned_int.c
** File description:
** Display an unsigned int.
*/

#include <stdarg.h>
#include "my.h"

static
int my_unsigned_count(int nb)
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

int my_put_unsigned_int(unsigned int nbr)
{
    int total = my_unsigned_count(nbr);

    if (nbr <= 9) {
        my_putchar(nbr + 48);
        return 1;
    }
    if (nbr > 9) {
        my_put_unsigned_int(nbr / 10);
        my_put_unsigned_int(nbr % 10);
    }
    return total;
}
