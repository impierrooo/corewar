/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar.c
** my_putchar(i != 0 && i % 2 == 0 ? ' ' : '\0');
*/

#include "project.h"
#include <stddef.h>

static
void display_arena(char *arena)
{
    for (int i = 0; i < S_MOD; i++) {
        if (i != 0 && i % 64 == 0)
            my_putchar(i == 0 ? '\0' : '\n');
        my_putchar(arena[i] - (arena[i] >= 'a' && arena[i] <= 'z' ? 32 : 0));
    }
    my_putchar('\n');
}

static
void display_winner(champion_t *champion)
{
    my_putstr("The player ");
    my_put_nbr(champion->id);
    my_putchar('(');
    my_putstr(champion->header->prog_name);
    my_putstr(")has won.\n");
    return;
}

static
void get_winner(corewar_t *vm, champion_t **champions)
{
    int remaining_champs = 0;
    int i_last = 0;
    int last_live = champions[0]->last_live;

    for (int i = 0; i < vm->nbr_champs; i++)
        remaining_champs += champions[i]->alive;
    for (int i = 0; i < vm->nbr_champs; i++)
        if (champions[i]->last_live < last_live) {
            last_live = champions[i]->last_live;
            i_last = i;
        }
    return display_winner(champions[i_last]);
}

static
int is_ended(corewar_t *vm, champion_t **champions)
{
    int remaining_champs = 0;

    if (vm->remaining_cycles == 0)
        return 1;
    if (vm->nb_live > NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nb_live = 0;
    }
    for (int i = 0; i < vm->nbr_champs; i++) {
        champions[i]->last_live++;
        champions[i]->alive = champions[i]->last_live < vm->cycle_to_die;
    }
    if (vm->remaining_cycles > 0)
        return 0;
    for (int i = 0; i < vm->nbr_champs; i++)
        remaining_champs += champions[i]->alive;
    return remaining_champs == 1;
}

int corewar(corewar_t *vm, champion_t **champions)
{
    if (vm == NULL || champions == NULL) {
        destroy_all(vm, champions);
        return 84;
    }
    while (is_ended(vm, champions) == 0) {
        if (check_instructions(vm, champions) == -1) {
            break;
        }
        if (vm->remaining_cycles > 0)
            vm->remaining_cycles -= 1;
    }
    if (vm->remaining_cycles != -1)
        display_arena(vm->arena);
    get_winner(vm, champions);
    destroy_all(vm, champions);
    return 0;
}
