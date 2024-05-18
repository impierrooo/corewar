/*
** EPITECH PROJECT, 2023
** my get nbr
** File description:
** Write a function that returns a number, sent to the function as a string.
*/

#include "my.h"

static int my_get_len_num(char const *str, int start)
{
    int longueur = 0;
    int i = start;

    while (str[i] >= 48 && str[i] <= 57) {
        longueur++;
        i++;
    }
    return longueur;
}

static int my_stock_number(int start, char const *str, int len)
{
    int renvoi = 0;
    int k = 1;

    for (int j = start; j < (start + len + 1) && k < len + 1; j++) {
        renvoi += (str[j] - 48) * power(10, (len - k));
        k += 1;
    }
    return renvoi;
}

int my_getnbr(char const *str)
{
    int sign = 1;
    int len_str = my_strlen(str);
    int len_nbr = 0;

    for (int i = 0; i < len_str; i++) {
        if (str[i] == '-')
            sign = sign * (- 1);
        if (str[i] >= 48 && str[i] <= 57) {
            len_nbr = my_get_len_num(str, i);
            break;
        }
    }
    for (int i = 0; i < len_str; i++) {
        if (str[i] >= 48 && str[i] <= 57)
            return my_stock_number(i, str, len_nbr) * sign;
    }
    return -1;
}
