/*
** EPITECH PROJECT, 2023
** my_put_ptr.c
** File description:
** Display a pointer's address in hexa.
*/

#include "my.h"
#include <stdlib.h>

static
char *my_get_ptr(long long nbr)
{
    char const *base = "0123456789abcdef";
    char *result = malloc(16 * sizeof(char));
    int i = 0;

    if (result == NULL)
        return 0;
    while (nbr != 0) {
        result[i] = base[nbr % 16];
        nbr /= 16;
        i ++;
    }
    my_revstr(result);
    return result;
}

int my_put_ptr(long long ptr)
{
    my_putchar('0');
    my_putchar('x');
    return my_putstr(my_get_ptr(ptr)) + 2;
}
