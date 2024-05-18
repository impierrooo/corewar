/*
** EPITECH PROJECT, 2023
** my_put_nbr_base.c
** File description:
** Displays a number in the given base (2, 8, 10 or 16).
** return
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_get_len_base(unsigned int nbr, char *base)
{
    char *result = malloc(sizeof(char));
    int i = 0;

    while (nbr != 0) {
        result[i] = base[nbr % my_strlen(base)];
        nbr = nbr / my_strlen(base);
        i++;
    }
    return my_strlen(result);
}

int my_putnbr_base(unsigned int nbr, char *base)
{
    char *result = malloc(sizeof(char));
    int i = 0;

    while (nbr != 0) {
        result[i] = base[nbr % my_strlen(base)];
        nbr = nbr / my_strlen(base);
        i++;
    }
    my_revstr(result);
    return my_putstr(result);
}
