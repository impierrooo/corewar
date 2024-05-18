/*
** EPITECH PROJECT, 2024
** my lib
** File description:
** copy_array.c
*/

#include "my.h"
#include <stdlib.h>

char **copy_array(char **array)
{
    int size = my_arraylen(array);
    char **result = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size; i ++) {
        result[i] = my_strdup(array[i]);
    }
    result[size] = NULL;
    return result;
}
