/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** destroy_champions.c
*/

#include "project.h"
#include <stdlib.h>

void destroy_champions(champion_t **champions, int nbr_champs)
{
    if (champions == NULL)
        return;
    for (int i = 0; i < nbr_champs; i++) {
        free(champions[i]->header);
        free_array(champions[i]->tab);
        free(champions[i]);
    }
    free(champions);
}
