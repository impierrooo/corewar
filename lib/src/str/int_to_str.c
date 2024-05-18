/*
** EPITECH PROJECT, 2023
** lib
** File description:
** int_to_str.c
*/

#include "my.h"
#include <stdlib.h>

static char *str_is_zero(char *result)
{
    result[0] = '0';
    result[1] = '\0';
    return result;
}

char *int_to_str(int n)
{
    int nb_len = my_digit_count(n);
    char *result = malloc(sizeof(char) * (nb_len + 1));

    if (n == 0)
        return str_is_zero(result);
    while (n > 0) {
        if (n < 0) {
            my_strcat_char(result, '-');
            n = n * (- 1);
        }
        if (n <= 9)
            my_strcat_char(result, (n + 48));
        if (n > 9) {
            my_strcat_char(result, ((n % 10) + 48));
        }
        n /= 10;
    }
    my_revstr(result);
    result[nb_len] = '\0';
    return result;
}
