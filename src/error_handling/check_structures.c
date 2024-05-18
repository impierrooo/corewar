/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_structures.c
*/

#include "project.h"

static
void display_header_infos(header_t *header)
{
    my_printf("\nprog_name: %s\n", header->prog_name);
    my_printf("magic: %x\n", header->magic);
    my_printf("prog_size: %d\n", header->prog_size);
    my_printf("comment: %s\n", header->comment);
}

void check_structures(corewar_t *vm, champion_t **champions)
{
    my_printf("---------- virtual machine ----------\n");
    my_printf("nbr_champs: %d\n", vm->nbr_champs);
    my_printf("remaining_cycles: %d\n", vm->remaining_cycles);
    my_printf("------------- champions -------------\n\n");
    for (int i = 0; i < vm->nbr_champs; i++) {
        my_printf("------------ champion %d------------\n", i + 1);
        display_header_infos(champions[i]->header);
        my_printf("address: %d\nid: %d\n", champions[i]->address,
            champions[i]->id);
        my_putstr("\n");
    }
    my_printf("Arena:\n[%s]\n\n", vm->arena);
    for (int j = 0; j < vm->nbr_champs; j++) {
        my_printf("Tête de lecture du champion %d\n",
            champions[j]->reading_head);
    }
}
