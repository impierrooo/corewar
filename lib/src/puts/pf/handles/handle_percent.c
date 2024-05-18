/*
** EPITECH PROJECT, 2023
** handle percent
** File description:
** handles the %% case and it's flags
*/

#include "my.h"

int handle_percent(p_info_t *p_info, parser_t *parse)
{
    char arg = '%';
    int rest = parse->width - 1;

    if (is_in('-', parse->flag))
        return my_putchar(arg) + display_rest(rest, ' ');
    p_info->total += 0;
    return display_rest(rest, ' ') + my_putchar(arg);
}
