/*
** EPITECH PROJECT, 2023
** handle g
** File description:
** handles %g and it's flags
*/

#include "my.h"
#include <stdlib.h>

int handle_gmaj(p_info_t *p_info, parser_t *parse)
{
    double arg = va_arg(p_info->v_list, double);

    if (parse->precision < 0)
        return my_put_nbr_gmaj(arg, 6);
    if (parse->precision >= 0)
        return my_put_nbr_gmaj(arg, parse->precision);
    return 0;
}