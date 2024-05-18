/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_aff.c
*/

#include "project.h"

int exec_aff(corewar_t *vm, champion_t *champion, int head_i)
{
    char **param_type = separate_coding_byte(vm->arena + head_i + 2);
    int size = get_param_size(param_type);
    int param = hex_to_int(get_byte(vm->arena + head_i + 4)) - 1;

    champion->stun--;
    if (champion->stun == -1) {
        free_array(param_type);
        return stun(champion, (champion->stun == -1) ? 2 : champion->stun);
    }
    my_putchar(champion->registers[param] % 256);
    my_putchar('\n');
    free_array(param_type);
    return size * 2 + 2;
}
