/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_instruction.c
*/

#include "project.h"
#include <stddef.h>

static const
function_ptr_t functs[16] = {{"01", &(exec_live)},
    {"02", &(exec_ld)},
    {"03", &(exec_st)},
    {"04", &(exec_add)},
    {"05", &(exec_sub)},
    {"06", &(exec_and)},
    {"07", &(exec_or)},
    {"08", &(exec_xor)},
    {"09", &(exec_zjmp)},
    {"0a", &(exec_ldi)},
    {"0b", &(exec_sti)},
    {"0c", &(exec_fork)},
    {"0d", &(exec_lld)},
    {"0e", &(exec_lldi)},
    {"0f", &(exec_lfork)},
    {"10", &(exec_aff)}};

static
int check_instruction(corewar_t *vm, champion_t *cha)
{
    for (int i = 0; i < 16; i++) {
        if (my_strcmp(vm->arena + (cha->reading_head % S_MOD),
            functs[i].instruction) == 0)
            return functs[i].function(vm, cha, cha->reading_head % S_MOD);
        if (my_strcmp(vm->arena + (cha->reading_head % S_MOD), "00") == 0)
            return 0;
    }
    return 0;
}

int check_instructions(corewar_t *vm, champion_t **champs)
{
    int i = 0;
    int return_status = 0;

    while (i < vm->nbr_champs) {
        if (champs[i]->tab == NULL)
            return 84;
        return_status = check_instruction(vm, champs[i]);
        champs[i]->reading_head += return_status + 2;
        if (return_status == -1)
            return -1;
        i++;
    }
    return 0;
}
