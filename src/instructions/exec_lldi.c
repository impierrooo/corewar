/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_lldi.c
*/

#include "project.h"
#include <stdlib.h>

static
void execute_params(corewar_t *vm, champion_t *champion,
    int *params_value, int head_i)
{
    int p1 = params_value[0];
    int p2 = params_value[1];
    int p3 = params_value[2];
    int offset = head_i + ((p1 * 2));
    char *temp = get_from_arena(vm->arena + (offset) % S_MOD,
        IND_SIZE * 2);
    int sum = (hex_to_int(temp) + p2) * 2;

    temp = get_from_arena(vm->arena + (head_i + sum) % S_MOD,
        REG_SIZE * 2);
    champion->registers[p3] = hex_to_int(temp);
    champion->carry = champion->registers[p3] == 0 ? 1 : 0;
}

static
int get_ldi_size(char **param_type)
{
    int size = 0;

    for (int i = 0; i < 3; i++) {
        if (my_strcmp(param_type[i], DIRECT) == 0)
            size += 2;
        if (my_strcmp(param_type[i], INDIRECT) == 0)
            size += 2;
        if (my_strcmp(param_type[i], REGISTER) == 0)
            size++;
    }
    return size;
}

static
int *get_ldi_params(char **param_type, corewar_t *vm, int head_i)
{
    int *params = malloc(sizeof(int) * 3);
    int offset = head_i + 4;
    int param_size = 0;

    for (int i = 0; i < 4; i++) {
        if (my_strcmp(param_type[i], "00") == 0)
            return params;
        if (my_strcmp(param_type[i], REGISTER) == 0)
            param_size = 2;
        else
            param_size = 4;
        params[i] = hex_to_int(get_from_arena(vm->arena + offset, param_size));
        offset += param_size;
    }
    return params;
}

static
int *get_params_value(corewar_t *vm, champion_t *champion, char **param_type)
{
    int *params = get_ldi_params(param_type, vm, champion->reading_head);
    int offset = champion->reading_head + 4;
    int *params_value = malloc(sizeof(int) * 3);

    if (my_strcmp(param_type[0], REGISTER) == 0)
        params_value[0] = champion->registers[params[0] - 1];
    else
        params_value[0] = get_index(get_from_arena(vm->arena + offset, 4));
    offset += my_strcmp(param_type[0], REGISTER) == 0 ? 2 : 4;
    if (my_strcmp(param_type[1], REGISTER) == 0)
        params_value[1] = champion->registers[params[1] - 1];
    else
        params_value[1] = get_index(get_from_arena(vm->arena + offset, 4));
    params_value[2] = params[2] - 1;
    free(params);
    return params_value;
}

int exec_lldi(corewar_t *vm, champion_t *champion, int head_i)
{
    char **param_type = separate_coding_byte(vm->arena + head_i + 2);
    int size = get_ldi_size(param_type);
    int *params_value = get_params_value(vm, champion, param_type);

    champion->stun--;
    if (champion->stun != 0) {
        free_array(param_type);
        free(params_value);
        return stun(champion, (champion->stun == -1) ? 50 : champion->stun);
    }
    execute_params(vm, champion, params_value, head_i);
    free_array(param_type);
    free(params_value);
    return size * 2 + 2;
}
