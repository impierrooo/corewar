/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** Does the same thing as the function printf.
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int my_printf(const char *format, ...)
{
    int i = 0;
    char letter = format[i];
    p_info_t *p_info = malloc(sizeof(p_info_t));
    parser_t *parse = malloc(sizeof(parser_t));

    va_start(p_info->v_list, format);
    while (letter != '\0') {
        if (letter == '%') {
            i ++;
            letter = format[i];
            parse = my_parser(format, i);
            p_info->total += display_arg(letter, p_info, parse);
        } else
            p_info->total += my_putchar(letter);
        i ++;
        letter = format[i];
    }
    va_end(p_info->v_list);
    return p_info->total;
}
