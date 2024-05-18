/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_and.c
*/

#include "project.h"
#include <stdlib.h>

static
int *get_values(char **type, champion_t *champ, corewar_t *vm, int *param)
{
    int *result = malloc(sizeof(char) * 3);
    int offset = 0;

    for (int i = 0; i < 3; i ++) {
        if (my_strcmp(type[i], REGISTER) == 0)
            result[i] = champ->registers[param[i] - 1];
        if (my_strcmp(type[i], DIRECT) == 0)
            result[i] = param[i];
        if (my_strcmp(type[0], INDIRECT) == 0) {
            offset = (((param[i] * 2) % IDX_MOD) % S_MOD);
            result[i] = get_index(get_from_arena(
                vm->arena + offset, REG_SIZE * 2));
        }
    }
    free(param);
    return result;
}

int exec_and(corewar_t *vm, champion_t *champion, int head_i)
{
    char **param_type = separate_coding_byte(vm->arena + head_i + 2);
    int size = get_param_size(param_type);
    int *param = get_params(vm, head_i, param_type, 3);
    int *param_value = NULL;

    champion->stun--;
    if (champion->stun == -1) {
        free(param);
        free_array(param_type);
        return stun(champion, (champion->stun == -1) ? 6 : champion->stun);
    }
    param_value = get_values(param_type, champion, vm, param);
    champion->registers[param_value[2]] = param_value[0] & param_value[1];
    champion->carry = (param_value[0] & param_value[1]) == 0 ? 1 : 0;
    free(param_value);
    free_array(param_type);
    return size * 2 + 2;
}
