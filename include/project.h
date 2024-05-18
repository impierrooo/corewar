/*
** EPITECH PROJECT, 2024
** general_lib
** File description:
** my_printf.h
*/

#ifndef PROJECT_H
    #define PROJECT_H

    #include "structures.h"
    #include "my.h"


int corewar(corewar_t *vm, champion_t **champions);

int help(char **argv, int argc);

/****************/
/*    PARSING   */
/****************/

int check_instructions(corewar_t *vm, champion_t **champions);
int check_number(char *str, int *result);
int set_prog_number(char **argv, int argc, int *i, champion_t *champion);
int set_address(char **argv, int argc, int *i, champion_t *champion);
int set_dump(char **argv, int argc, int *i, corewar_t *corewar);
char **get_champion_instructions(char *filepath, header_t *header);
int check_params(int ac, char **av, corewar_t *corewar, champion_t ***champs);
int hex_to_int(char *hex);
char *hexa_to_bin(char *hex);
char **separate_coding_byte(char *bin);
int get_param_size(char **param_type);
char *get_byte(char *arena);
char *get_from_arena(char *arena, int size);
int *get_params(corewar_t *vm, int head_i, char **param_type, int size);
int stun(champion_t *champ, int duration);
int get_index(char *byte);

/****************/
/*     INIT     */
/****************/

int getnbr_champs(int argc, char **argv);
int is_champion_path(char *path);
corewar_t *init_corewar(char **argv, int argc, champion_t ***champion);
int init_arena(corewar_t *vm, champion_t **champions);
header_t *get_header(char *filename);
champion_t **init_champions(int nbr, char **argv, int argc);
champion_t *init_champion(char *filepath, int *champ, int total);

int my_htobe(int num);

/****************/
/*   FUNCTION   */
/****************/

int exec_add(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_aff(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_and(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_fork(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_ld(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_ldi(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_lfork(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_live(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_lld(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_lldi(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_or(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_st(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_sti(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_sub(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_xor(corewar_t *corewar, champion_t *champion, int reading_head);
int exec_zjmp(corewar_t *corewar, champion_t *champion, int reading_head);


/****************/
/*    DESTROY   */
/****************/

void destroy_all(corewar_t *vm, champion_t **champions);
void destroy_champions(champion_t **champions, int nbr_champs);
void free_corewar(corewar_t *corewar);

void check_structures(corewar_t *vm, champion_t **champions);

#endif /* PROJECT_H */
