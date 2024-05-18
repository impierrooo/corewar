/*
** EPITECH PROJECT, 2023
** my handle s
** File description:
** handles the %s case and it's associated flags && length modifiers
*/

#include "my.h"

int handle_s(p_info_t *p_info, parser_t *parse)
{
    char *arg = va_arg(p_info->v_list, char *);
    int len_str = my_strlen(arg);
    int rest = parse->width - len_str;

    if (is_in('-', parse->flag))
        return my_putstr(arg) + display_rest(rest, ' ');
    return display_rest(rest, ' ') + my_putstr(arg);
}
