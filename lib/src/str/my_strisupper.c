/*
** EPITECH PROJECT, 2023
** my str is upper
** File description:
** checks if a string is caps locked
*/

#include "my.h"
#include <stdlib.h>

int my_str_isupper(char const *str)
{
    char *ptr = malloc(sizeof(char) * my_strlen(str));

    my_strcpy(ptr, str);
    while (*ptr != '\0') {
        if (*ptr < 65 || *ptr > 90)
            return 0;
        ptr ++;
    }
    return 1;
}
