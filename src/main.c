/*
** EPITECH PROJECT, 2023
** $PROJECT NAME
** File description:
** main.c
*/

#include "project.h"
#include <stddef.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    corewar_t *vm = NULL;
    champion_t **champions = NULL;

    vm = init_corewar(argv, argc, &champions);
    if (vm == NULL)
        return 84;
    return corewar(vm, champions);
}
