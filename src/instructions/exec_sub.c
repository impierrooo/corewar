/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_sub.c
*/

#include "project.h"
#include <stdlib.h>

int exec_sub(corewar_t *vm, champion_t *champion, int head_i)
{
    char **param_type = separate_coding_byte(vm->arena + head_i + 2);
    int size = get_param_size(param_type);
    int params[3] = { 0 };
    int sum = 0;

    champion->stun--;
    if (champion->stun == -1) {
        free_array(param_type);
        return stun(champion, (champion->stun == -1) ? 10 : champion->stun);
    }
    params[0] = hex_to_int(get_byte(vm->arena + head_i + 4)) - 1;
    params[1] = hex_to_int(get_byte(vm->arena + head_i + 6)) - 1;
    params[2] = hex_to_int(get_byte(vm->arena + head_i + 8)) - 1;
    sum = champion->registers[params[0]];
    sum -= champion->registers[params[1]];
    champion->registers[params[2]] = sum;
    champion->carry = sum == 0 ? 1 : 0;
    free_array(param_type);
    return size * 2 + 2;
}
