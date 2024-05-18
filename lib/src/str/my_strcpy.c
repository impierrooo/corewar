/*
** EPITECH PROJECT, 2023
** MY STR COPY
** File description:
** copies the src str in the dest
*/

#include <stdlib.h>
#include "my.h"

void my_strcpy(char *dest, char const *src)
{
    int len_src = my_strlen(src);

    for (int i = 0; i < my_strlen(src); i++)
        dest[i] = src[i];
    dest[len_src] = '\0';
    return;
}

void my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return;
}
