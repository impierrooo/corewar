/*
** EPITECH PROJECT, 2023
** my show word array
** File description:
** show words in an array
*/

#include "my.h"
#include <stdlib.h>

int my_show_word_array(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putchar('[');
        my_putstr(tab[i]);
        my_putchar(']');
        my_putchar('\n');
        i++;
    }
    return i;
}
