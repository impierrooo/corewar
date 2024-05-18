/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_champ.c
*/

#include "project.h"
#include <stdlib.h>

static
champion_t *freen(champion_t *champion)
{
    free(champion);
    return NULL;
}

champion_t **init_champions(int nbr, char **argv, int argc)
{
    champion_t **result = malloc(sizeof(champion_t *) * nbr);
    int k = 0;

    for (int i = 1; i < argc; i++) {
        if (is_champion_path(argv[i]) == 1)
            result[k] = init_champion(argv[i], &k, nbr);
    }
    for (k = 0; k < nbr; k++) {
        if (result[k] == NULL) {
            destroy_champions(result, k);
            return NULL;
        }
    }
    return result;
}

champion_t *init_champion(char *filepath, int *champ, int total)
{
    champion_t *result = malloc(sizeof(champion_t));

    result->header = get_header(filepath);
    if (result->header == NULL)
        return freen(result);
    result->id = (*champ) + 1;
    result->address = (MEM_SIZE * 2) / total * (*champ);
    result->tab = get_champion_instructions(filepath, result->header);
    result->reading_head = 0;
    result->last_live = 0;
    result->carry = 1;
    result->stun = 0;
    result->alive = 1;
    for (int i = 0; i < REG_NUMBER; i++)
        result->registers[i] = 0;
    result->registers[REG_NUMBER] = -1;
    result->registers[0] = result->id;
    (*champ)++;
    return result;
}
