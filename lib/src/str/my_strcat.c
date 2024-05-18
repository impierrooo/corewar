/*
** EPITECH PROJECT, 2023
** my str cat
** File description:
** concatenates two strings
*/

#include "my.h"

void my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);

    for (int i = 0; i < src_len; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + src_len] = '\0';
}

void my_strncat(char *dest, char const *src, int n)
{
    int len_dest = my_strlen(dest);

    for (int i = 0; i < n; i++)
        dest[len_dest + i] = src[i];
    dest[len_dest + n] = '\0';
}

void my_strcat_char(char *dest, char src)
{
    int len_dest = my_strlen(dest);

    dest[len_dest] = src;
    dest[len_dest + 1] = '\0';
}
