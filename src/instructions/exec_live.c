/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** exec_live.c
*/

#include "project.h"
#include <stdlib.h>

static
void display_champ(champion_t *champion)
{
    my_putstr("The player ");
    my_put_nbr(champion->id);
    my_putchar('(');
    my_putstr(champion->header->prog_name);
    my_putstr(")is alive.\n");
}

int exec_live(corewar_t *vm, champion_t *champion, int pc)
{
    char *param = malloc(sizeof(char) * 9);
    int id = 0;

    champion->stun--;
    if (champion->stun == -1) {
        free(param);
        return stun(champion, (champion->stun == -1) ? 10 : champion->stun);
    }
    for (int i = 0; i < 8; i++)
        param[i] = '\0';
    param[8] = '\0';
    my_strncat(param, vm->arena + (pc + 2), 8);
    id = hex_to_int(param);
    if (id == champion->id) {
        champion->last_live = 0;
        vm->nb_live += 1;
        display_champ(champion);
        return 8;
    }
    return 8;
}
