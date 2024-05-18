/*
** EPITECH PROJECT, 2023
** my put nbr
** File description:
** display the number
*/

#include <stdarg.h>
#include "my.h"

int my_digit_count(int nb)
{
    int i = 0;

    while (nb > 9) {
        i++;
        nb = nb / 10;
    }
    return i + 1;
}

int my_put_nbr(int n)
{
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
    return my_digit_count(n);
}
