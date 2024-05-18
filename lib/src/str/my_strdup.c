/*
** EPITECH PROJECT, 2023
** my strdup
** File description:
** allocates memory and copies the string given to it
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

char *my_strdup(char *src)
{
    int len_src = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len_src + 1));

    if (!dest)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}

char *my_strndup(char *src, int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));

    if (!dest)
        return NULL;
    my_strncpy(dest, src, n);
    return dest;
}
