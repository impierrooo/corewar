/*
** EPITECH PROJECT, 2024
** my lib
** File description:
** free_array.c
*/

#include "my.h"
#include <stdlib.h>

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i] != NULL; i ++)
        free(array[i]);
    free(array);
}
