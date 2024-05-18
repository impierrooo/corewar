/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** is_in.c
*/

#include "my.h"

/**
 * @brief Check if a character is present in a string
 *
 * @param c The character to search for
 * @param str The string to search in
 * @return int 1 if the character is found, 0 otherwise
 */
int is_in(char c, char *str)
{
    int i = 0;
    int len_str = my_strlen(str);

    while (i < len_str) {
        if (str[i] == c)
            return 1;
        i ++;
    }
    return 0;
}

int is_str_in(char *str, char const *to_find)
{
    int len_to_find = my_strlen(to_find);
    int len_str = my_strlen(str);
    int flag = 84;
    char *ptr_str = str;

    if (len_str < len_to_find)
        return 0;
    if (len_str == len_to_find) {
        if (my_strcmp(str, to_find) == 0)
            return 1;
        return 0;
    }
    while (*ptr_str != '\0') {
        if (*ptr_str == to_find[0])
            flag = my_strncmp(ptr_str, to_find, len_to_find);
        if (flag == 0)
            return 1;
        ptr_str++;
    }
    return 0;
}
