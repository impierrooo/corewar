/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_st.c
*/


#include "project.h"
#include <stdlib.h>

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
void write_in_arena(corewar_t *vm, champion_t *champ, int head_i, int value)
{
    int to_write = champ->registers[value - 1];
    char *hex = dec_to_hex(to_write, "0123456789abcdef");

    for (int i = 0; i < 8; i++)
        vm->arena[(head_i + i) % S_MOD] = hex[i];
    free(hex);
}

static
void get_values(corewar_t *vm, int head_i, char **param_type, int *params)
{
    int type = 0;

    params[0] = hex_to_int(get_byte(vm->arena + head_i + 4));
    type = my_strcmp(param_type[1], INDIRECT) == 0 ? 4 : 2;
    if (type == 4)
        params[1] = get_index(get_from_arena(vm->arena + head_i + 6, type));
    if (type == 2)
        params[1] = hex_to_int(get_from_arena(vm->arena + head_i + 6, type));
}

int exec_st(corewar_t *vm, champion_t *champion, int head_i)
{
    char **param_type = separate_coding_byte(vm->arena + head_i + 2);
    int size = get_param_size(param_type);
    int type = 0;
    int params[2] = { 0 };

    champion->stun--;
    if (champion->stun != 0) {
        free_array(param_type);
        return stun(champion, (champion->stun == -1) ? 5 : champion->stun);
    }
    get_values(vm, head_i, param_type, params);
    if (type == 4)
        write_in_arena(vm, champion,
            (head_i + (params[1]) % IDX_MOD) % S_MOD, params[0]);
    if (type == 2)
        champion->registers[params[1] - 1] =
            champion->registers[params[0] - 1];
    free_array(param_type);
    return size * 2 + 2;
}
