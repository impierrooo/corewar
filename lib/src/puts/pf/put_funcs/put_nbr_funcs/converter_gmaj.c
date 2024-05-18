/*
** EPITECH PROJECT, 2023
** my_put_nbr_g.c
** File description:
** Display number in float or in scientific mode.
*/

#include <stdio.h>
#include "my.h"

static
int calcul_count(double nb, int count)
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

static
int count_lenght(int nb)
{
    int i = 0;
    int modulo = nb % 10;

    while (modulo == 0) {
        nb = nb / 10;
        modulo = nb % 10;
        i = i +1;
    }
    return i;
}

static
int my_digit_count_ent(int nb)
{
    int i = 1;

    while (nb > 9) {
        nb = nb / 10;
        i = i + 1;
    }
    return i;
}

static
int inferior(double nb)
{
    if (nb < 0) {
        nb = - nb;
        my_putstr("-");
    }
    return nb;
}

int my_put_nbr_gmaj(double nb, int precision)
{
    mystruct_t stock = {0, 0, 0, 0, 0, 0};

    if (nb == 0) {
        my_putstr("0");
        return 1;
    }
    nb = inferior(nb);
    stock.count = calcul_count(nb, stock.count);
    if (stock.count < precision) {
        stock.num_ent = nb;
        stock.num_dec = nb - stock.num_ent;
        stock.num_dec = nb * power(10, precision);
        if (stock.num_dec == 0)
            return my_put_float(nb, 0);
        stock.lenght = count_lenght(stock.num_dec);
        stock.lenght_ent = my_digit_count_ent(stock.num_ent);
        return my_put_float(nb, precision - stock.lenght_ent);
    }
    stock.lenght_ent = my_digit_count_ent(stock.num_dec);
    return my_put_nbr_scientific_emaj(nb, precision - stock.lenght_ent) - 1;
}
