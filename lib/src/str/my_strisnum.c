/*
** EPITECH PROJECT, 2023
** my str is number
** File description:
** checks if a string is only composed by numbers
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int len_str = my_strlen(str);

    if (len_str == 0)
        return 1;
    if (len_str == 1)
        return IS_NUMBER(str[0]);
    for (int i = 0; i < len_str; i++) {
        if (IS_NUMBER(str[i]) == 0)
            return 0;
    }
    return 1;
}
