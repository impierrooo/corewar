/*
** EPITECH PROJECT, 2023
** my str str
** File description:
** finds a str within another
*/

#include <stdlib.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int len_to_find = my_strlen(to_find);
    int len_str = my_strlen(str);
    int flag = 84;
    char *ptr_str = str;

    if (len_str < len_to_find)
        return NULL;
    if (len_str == len_to_find) {
        if (my_strcmp(str, to_find) == 0)
            return str;
        return NULL;
    }
    while (*ptr_str != '\0') {
        if (*ptr_str == to_find[0])
            flag = my_strncmp(ptr_str, to_find, len_to_find);
        if (flag == 0)
            return ptr_str;
        ptr_str++;
    }
    return NULL;
}
