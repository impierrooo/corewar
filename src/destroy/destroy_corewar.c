/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** destroy_corewar.c
*/

#include <stdlib.h>
#include "project.h"

void free_corewar(corewar_t *corewar)
{
    if (corewar == NULL)
        return;
    if (corewar->arena != NULL)
        free(corewar->arena);
    free(corewar);
}
