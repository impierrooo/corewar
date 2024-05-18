/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_instructions.c
*/

#include "project.h"
#include <stdlib.h>
#include <stdio.h>

static
char *dec_to_hexa_final(int i, char *str, char *hexa_Number)
{
    int n = 0;

    while (i > 1) {
        i--;
        if (hexa_Number[i] >= 'A' && hexa_Number[i] <= 'Z')
            hexa_Number[i] += 32;
        str[n] = hexa_Number[i];
        n++;
    }
    str[n] = '\0';
    if (my_strlen(str) == 1) {
        str[2] = str[1];
        str[1] = str[0];
        str[0] = '0';
    }
    return str;
}

static
char *dec_to_hexa_conversion(int decimal_Number, char *str)
{
    int i = 1;
    int temp = 1;
    char hexa_Number[3] = { 0 };

    if (decimal_Number == 0){
        str[0] = '0';
        str[1] = '0';
        return "00";
    }
    while (decimal_Number != 0) {
        temp = decimal_Number % 16;
        if (temp < 10)
            hexa_Number[i] = temp + '0';
        else
            hexa_Number[i] = temp + 'A' - 10;
        i++;
        decimal_Number = decimal_Number / 16;
    }
    return dec_to_hexa_final(i, str, hexa_Number);
}

static
char **open_champion(char **result, char *filepath, header_t *header)
{
    FILE *fp = fopen(filepath, "rb");
    int n = 0;
    int i = 0;
    char str[3] = { 0 };

    fseek(fp, 2192, SEEK_CUR);
    for (i = 0; i < header->prog_size; i++) {
        fread(&n, 1, 1, fp);
        dec_to_hexa_conversion(n, str);
        result[i] = malloc(sizeof(char) * 3);
        result[i][0] = str[0];
        result[i][1] = str[1];
        result[i][2] = '\0';
    }
    result[i] = NULL;
    fclose(fp);
    return result;
}

char **get_champion_instructions(char *filepath, header_t *header)
{
    char **result = malloc(sizeof(char *) * (header->prog_size + 1));

    result[header->prog_size] = NULL;
    return open_champion(result, filepath, header);
}
