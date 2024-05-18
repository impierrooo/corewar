/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_sti.c
*/

#include "project.h"
#include <stdlib.h>

static
int get_sti_size(char **param_type)
{
    int size = 0;

    for (int i = 0; i < 3; i++) {
        if (my_strcmp(param_type[i], REGISTER) == 0)
            size++;
        if (my_strcmp(param_type[i], DIRECT) == 0)
            size += 2;
        if (my_strcmp(param_type[i], INDIRECT) == 0)
            size += 2;
    }
    return size;
}

static
int *get_sti_params(char **param_type, corewar_t *vm, int head_i)
{
    int *params = malloc(sizeof(int) * 3);
    int offset = head_i + 4;
    int param_size = 0;

    params[0] = hex_to_int(get_byte(vm->arena + offset % S_MOD));
    for (int i = 1; i < 3; i++) {
        if (my_strcmp(param_type[i], "00") == 0)
            return params;
        if (my_strcmp(param_type[i], REGISTER) == 0)
            param_size = 2;
        else
            param_size = 4;
        params[i] = hex_to_int(get_from_arena(vm->arena + offset % S_MOD,
            param_size));
        offset += param_size;
    }
    return params;
}

static
int *get_values(corewar_t *vm, champion_t *champion, char **param_type)
{
    int *params = get_sti_params(param_type, vm, champion->reading_head);
    int offset = champion->reading_head + 4;
    int *params_value = malloc(sizeof(int) * 3);

    params_value[0] = champion->registers[params[0] - 1];
    offset += 2;
    if (my_strcmp(param_type[1], REGISTER) == 0)
        params_value[1] = champion->registers[params[1] - 1];
    else
        params_value[1] = get_index(get_from_arena(vm->arena + offset, 4));
    offset += my_strcmp(param_type[1], REGISTER) == 0 ? 2 : 4;
    if (my_strcmp(param_type[2], REGISTER) == 0)
        params_value[2] = champion->registers[params[2] - 1];
    else
        params_value[2] = get_index(get_from_arena(vm->arena + offset, 4));
    free(params);
    return params_value;
}

static
char *dec_to_hex(int nbr, char *base)
{
    char *result = malloc(sizeof(char) * 9);
    int i = 0;

    for (int i = 0; i < 8; i++)
        result[i] = '0';
    result[8] = '\0';
    while (nbr != 0) {
        result[i] = base[nbr % my_strlen(base)];
        nbr = nbr / my_strlen(base);
        i++;
    }
    my_revstr(result);
    return result;
}

static
void write_in_arena(corewar_t *vm, int head_i, int value)
{
    char *hex = dec_to_hex(value, "0123456789abcdef");

    for (int i = 0; i < 8; i++)
        vm->arena[(head_i + i) % S_MOD] = hex[i];
    free(hex);
}

int exec_sti(corewar_t *vm, champion_t *champion, int head_i)
{
    char **param_type = separate_coding_byte(vm->arena + head_i + 2);
    int size = get_sti_size(param_type);
    int *values = get_values(vm, champion, param_type);
    int offset = (values[1] + values[2]) % IDX_MOD;

    champion->stun--;
    if (champion->stun != 0) {
        free_array(param_type);
        free(values);
        return stun(champion, (champion->stun == -1) ? 25 : champion->stun);
    }
    write_in_arena(vm, offset + head_i, values[0]);
    free_array(param_type);
    free(values);
    return size * 2 + 2;
}
