/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_lld.c
*/

#include "project.h"

int exec_lld(corewar_t *vm, champion_t *champion, int head_i)
{
    char **param_type = separate_coding_byte(vm->arena + head_i + 2);
    int size = get_param_size(param_type);
    int p_s = size * 2 - 2;
    int param[2] = { 0 };

    champion->stun--;
    if (champion->stun != 0) {
        free_array(param_type);
        return stun(champion, (champion->stun == -1) ? 10 : champion->stun);
    }
    param[0] = hex_to_int(get_from_arena(vm->arena + head_i + 4, p_s));
    param[1] = hex_to_int(get_from_arena(vm->arena + head_i + p_s + 4, 2));
    if (my_strcmp(param_type[0], INDIRECT) == 0)
        champion->registers[param[1] - 1] = get_index(get_from_arena(
        vm->arena + (head_i + ((param[0] * 2)) % S_MOD), 2));
    if (my_strcmp(param_type[0], DIRECT) == 0)
        champion->registers[param[1] - 1] = param[0];
    free_array(param_type);
    return size * 2 + 2;
}
