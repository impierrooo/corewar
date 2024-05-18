/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_corewar.c
*/

#include "project.h"
#include "stddef.h"
#include "stdlib.h"

corewar_t *init_corewar(char **argv, int argc, champion_t ***champions)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (corewar == NULL)
        return NULL;
    corewar->remaining_cycles = -1;
    corewar->nbr_champs = 0;
    corewar->nb_live = 0;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    if (check_params(argc, argv, corewar, champions) == HEADER_ERROR) {
        my_putstr_error("Header error.\n");
        destroy_all(corewar, *champions);
        return NULL;
    }
    if (init_arena(corewar, *champions) == -1) {
        my_putstr_error("INIT error.\n");
        destroy_all(corewar, *champions);
        return NULL;
    }
    return corewar;
}
