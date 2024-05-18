/*
** EPITECH PROJECT, 2023
** my compute square root
** File description:
** return the root of the number in parameter
*/

#include "my.h"

int square_root(int nb)
{
    int i = 0;

    while (i <= (nb / 2) && (power(i, 2)) != nb) {
        i ++;
    }
    if (i > nb / 2) {
        return 0;
    }
    return i;
}
