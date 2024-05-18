/*
** EPITECH PROJECT, 2024
** my lib
** File description:
** my_arraylen.c
*/

#include "my.h"
#include <stdlib.h>

int my_arraylen(char **array)
{
    int i = 0;

    if (!array)
        return -1;
    while (array[i] && array[i] != NULL) {
        i ++;
    }
    return i;
}
