/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_arena.c
*/

#include "project.h"
#include <stdlib.h>
#include <stddef.h>

int init_arena(corewar_t *vm, champion_t **champions)
{
    int k = 0;

    vm->arena = malloc(sizeof(char) * ((MEM_SIZE * 2) + 1));
    if (vm->arena == NULL)
        return -1;
    for (int i = 0; i < (MEM_SIZE * 2); i++)
        vm->arena[i] = '0';
    vm->arena[MEM_SIZE * 2] = '\0';
    for (int i = 0; i < vm->nbr_champs; i++) {
        champions[i]->reading_head = champions[i]->address;
        k = 0;
        for (int j = 0; j < champions[i]->header->prog_size; j++) {
            vm->arena[champions[i]->address + k] = champions[i]->tab[j][0];
            k++;
            vm->arena[champions[i]->address + k] = champions[i]->tab[j][1];
            k++;
        }
    }
    return 0;
}
