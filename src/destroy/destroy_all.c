/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** destroy_all.c
*/

#include "project.h"
#include <stddef.h>

void destroy_all(corewar_t *vm, champion_t **champions)
{
    if (vm != NULL)
        destroy_champions(champions, vm->nbr_champs);
    free_corewar(vm);
}
