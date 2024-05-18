/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_params.c
*/

#include "project.h"
#include <stdlib.h>

int *get_params(corewar_t *vm, int head_i, char **param_type, int size)
{
    int offset = head_i + 2;
    int *params = malloc(sizeof(int) * (size + 1));

    for (int i = 0; i < size; i++) {
        if (my_strcmp(param_type[i], REGISTER) == 0) {
            params[i] = hex_to_int(get_byte(vm->arena + offset)) - 1;
            offset += 2;
        }
        if (my_strcmp(param_type[i], DIRECT) == 0) {
            params[i] = hex_to_int(get_from_arena(vm->arena + offset, 8));
            offset += 8;
        }
        if (my_strcmp(param_type[i], INDIRECT) == 0) {
            params[i] = hex_to_int(get_from_arena(vm->arena + offset, 4));
            offset += 4;
        }
    }
    params[size] = -1;
    return params;
}

int stun(champion_t *champ, int duration)
{
    champ->stun = duration;
    return -2;
}
