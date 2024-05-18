/*
** EPITECH PROJECT, 2023
** my str isalpha
** File description:
** checks if a string is only composed of letters
*/

#include "my.h"

static int my_char_isalpha(char c)
{
    if ((c < 65 || c > 90)
        && (c < 97 || c > 122))
        return 0;
    return 1;
}

int my_str_isalpha(char const *str)
{
    int len_str = my_strlen(str);
    int flag = 1;

    if (len_str == 0)
        return flag;
    if (len_str == 1)
        return my_char_isalpha(str[0]);
    for (int i = 0; i < len_str; i++) {
        flag = my_char_isalpha(str[i]);
        if (flag == 0)
            return 0;
    }
    return flag;
}
