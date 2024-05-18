/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_zjmp.c
*/

#include "project.h"

int exec_zjmp(corewar_t *vm, champion_t *champion, int head_i)
{
    int jump = hex_to_int(get_from_arena(vm->arena + head_i + 2, 4));

    champion->stun--;
    if (champion->stun != 0)
        return stun(champion, champion->stun == -1 ? 20 : champion->stun);
    if (champion->carry != 1)
        return 4;
    if (jump > SHORT_OVERFLOW)
        jump -= SHORT_SIZE;
    jump += (jump > 0) ? 1 : -1;
    return jump * 2;
}
