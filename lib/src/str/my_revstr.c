/*
** EPITECH PROJECT, 2023
** my rev str
** File description:
** reverses a str
*/

#include "my.h"

void my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp;

    if (len < 2)
        return;
    for (int i = 0; i <= (len / 2); i++) {
        temp = str[len - i - 1];
        str[len - i - 1] = str[i];
        str[i] = temp;
    }
    if (len % 2 == 0) {
        temp = str[(len / 2) - 1];
        str[(len / 2) - 1] = str[len / 2];
        str[len / 2] = temp;
    }
}
