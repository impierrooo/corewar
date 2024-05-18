/*
** EPITECH PROJECT, 2023
** my_put_nbr_scientific_e.c
** File description:
** Display a number in scientific notation.
*/

#include "my.h"

static
int count_digit_float(int precision, int negative)
{
    int total = 5 + negative;

    if (precision == 0)
        return total;
    return total + precision + 1;
}

static
int display_zero(double nb, int precision)
{
    if (nb == 0) {
        my_putchar('0');
        if (precision != 0)
            my_putchar('.');
        for (int i = 0; i < precision; i += 1) {
            my_putstr("0");
        }
        my_putstr("e+00");
        return count_digit_float(precision, 0);
    }
    return 0;
}

static
int display(int count)
{
    my_putchar('e');
    my_putchar('+');
    if (count > 9) {
        my_put_nbr(count);
    } else {
        my_put_nbr(0);
        my_put_nbr(count);
    }
    return 0;
}

static
int calcul(double nb, int count)
{
    if (nb >= 10) {
        while (nb >= 10) {
            nb /= 10;
            count += 1;
        }
    }
    if (nb < 1) {
        while (nb < 1) {
            nb *= 10;
            count += 1;
        }
    }
    return count;
}

int my_put_nbr_scientific_e(double nb, int precision)
{
    int count = 0;
    int negative = 0;

    if (nb < 0) {
        my_putstr("-");
        nb = -nb;
        negative = 1;
    }
    display_zero(nb, precision);
    count = calcul(nb, count);
    for (int i = 1; nb >= 10; ++i)
        nb /= 10;
    for (int j = 1; nb < 1; ++j)
        nb *= 10;
    my_put_float(nb, precision);
    display(count);
    return count_digit_float(precision, negative);
}
