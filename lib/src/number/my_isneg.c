/*
** EPITECH PROJECT, 2023
** my isneg
** File description:
** return N if the parameter is negative and P if positive
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0){
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    return (0);
}
