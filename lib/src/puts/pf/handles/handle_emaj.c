/*
** EPITECH PROJECT, 2023
** handle e
** File description:
** handles e and it's flags
*/

#include "my.h"

int handle_emaj(p_info_t *p_info, parser_t *parse)
{
    double arg = va_arg(p_info->v_list, double);
    int precision = parse->precision;

    if (precision >= 0)
        return my_put_nbr_scientific_emaj(arg, precision);
    if (precision < 0)
        return my_put_nbr_scientific_emaj(arg, 6);
    return 0;
}
