/*
** EPITECH PROJECT, 2024
** general_lib
** File description:
** my_printf.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #define REGISTER "01"
    #define DIRECT "10"
    #define INDIRECT "11"
    #define S_MOD (MEM_SIZE * 2)

    #include "op.h"

typedef enum param_type_s {
    CHAMPION_PATH = 0,
    SET_ADDRESS = 1,
    SET_DUMP = 2,
    SET_PROG_NBR = 3,
    WRONG_FLAG = 4,
    HEADER_ERROR = -1,
} param_type_t;

typedef struct champion_s {
    char **tab;
    int reading_head;
    int registers[REG_NUMBER + 1];
    int id;
    int address;
    int last_live;
    int alive;
    int stun;
    int carry;
    header_t *header;
} champion_t;

typedef struct {
    int nbr_champs;
    int remaining_cycles;
    int nb_live;
    int cycle_to_die;
    char *arena;
} corewar_t;

typedef struct function_ptr_s {
    char *instruction;
    int (*function)(corewar_t *, champion_t *, int);
} function_ptr_t;

#endif /* STRUCT_H */
