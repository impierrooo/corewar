/*
** EPITECH PROJECT, 2023
** checks if a string is in full lowercase
** File description:
** my str is lower
*/

#include "my.h"
#include <stdlib.h>

int my_str_islower(char const *str)
{
    char *ptr = malloc(sizeof(char) * my_strlen(str));

    my_strcpy(ptr, str);
    while (*ptr != '\0') {
        if (*ptr < 97 || *ptr > 122)
            return 0;
        ptr ++;
    }
    return 1;
}
