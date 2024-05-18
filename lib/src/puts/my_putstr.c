/*
** EPITECH PROJECT, 2023
** my putstr
** File description:
** diplays the caracters of a string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return my_strlen(str);
}

int my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));
    return my_strlen(str);
}
