/*
** EPITECH PROJECT, 2023
** my_put_float.c
** File description:
** Display a float number.
*/

#include "my.h"

int display(int num_ent, int num_dec, int precision)
{
    my_put_nbr(num_ent);
    if (precision == 0)
        return 0;
    my_putchar('.');
    my_put_dec(num_dec, precision);
    return 0;
}

int my_digit_count_float(int nb)
{
    int i = 1;

    while (nb > 9) {
        nb = nb / 10;
        i = i + 1;
    }
    return i;
}

int my_put_dec(int num_dec, int precision)
{
    int calc_zero = (precision - my_digit_count_float(num_dec));

    if (num_dec == 0) {
        for (int i = 0; i < precision; i += 1) {
            my_putstr("0");
        }
        return 0;
    }
    if (my_digit_count_float(num_dec) != precision) {
        for (int j = 0; j < calc_zero; j += 1) {
            my_putstr("0");
        }
    }
    my_put_nbr(num_dec);
    return 0;
}

int my_put_float(double nb, int precision)
{
    int num_ent;
    int num_dec;
    int compare;
    int negatif = 1;

    if (nb < 0) {
        my_putstr("-");
        nb = nb * (- 1);
        negatif = negatif + 1;
    }
    num_ent = nb;
    nb = nb - num_ent;
    nb = nb * power(10, precision);
    num_dec = nb;
    compare = (nb + 0.5);
    num_dec = compare;
    display(num_ent, num_dec, precision);
    return my_digit_count_float(num_ent) + precision + negatif;
}
