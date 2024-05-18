/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_params.c
*/

#include "project.h"
#include <stddef.h>

static
int interprate_params(char **av, int ac,
    corewar_t *corewar, champion_t ***champs)
{
    int k = 0;
    int flag = WRONG_FLAG;
    int i = 1;

    for (; i < ac && k < corewar->nbr_champs; i++) {
        flag = is_champion_path(av[i]) == 1 ? CHAMPION_PATH : flag;
        if (my_strcmp(av[i], "-dump") == 0 && flag != HEADER_ERROR)
            flag = set_dump(av, ac, &i, corewar);
        if (my_strcmp(av[i], "-n") == 0 && flag != HEADER_ERROR)
            flag = set_prog_number(av, ac, &i, (*champs)[k]);
        if (my_strcmp(av[i], "-a") == 0 && flag != HEADER_ERROR)
            flag = set_address(av, ac, &i, (*champs)[k]);
        k += (is_champion_path(av[i]) == 1 ? 1 : 0);
        if (flag == WRONG_FLAG || flag == HEADER_ERROR)
            return HEADER_ERROR;
        flag = WRONG_FLAG;
    }
    return (i == ac) ? 0 : HEADER_ERROR;
}

int check_params(int ac, char **av, corewar_t *corewar, champion_t ***champs)
{
    int nbrchamps = getnbr_champs(ac, av);

    if (nbrchamps < 2 || nbrchamps > 4)
        return help(av, ac);
    *champs = init_champions(nbrchamps, av, ac);
    if (*champs == NULL)
        return 1;
    corewar->nbr_champs = nbrchamps;
    return interprate_params(av, ac, corewar, champs);
}
