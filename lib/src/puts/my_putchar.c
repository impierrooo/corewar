/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** prints a character
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int my_putchar_error(char c)
{
    write(2, &c, 1);
    return 1;
}
