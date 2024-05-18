/*
** EPITECH PROJECT, 2024
** my str header file
** File description:
** lists all the librabry's string functions in a header
*/

#ifndef STR_H
    #define STR_H

/**
 * @brief Returns the size of STR
*/
int my_strlen(char const *str);

/**
 * @brief Reverse a string
*/
void my_revstr(char *string);

/**
 * @brief Copies SRC to DEST
*/
void my_strcpy(char *dest, const char *src);

/**
 * @brief Copies N char of SRC to DEST
*/
void my_strncpy(char *dest, const char *src, int n);

/**
 * @brief Compare S1 and S2
 * @return 0 if S1 == S2
 * @return , -1 if S1 < S2
 * @return , 1 if S1 > S2
*/
int my_strcmp(const char *s1, const char *s2);

/**
 * @brief Compare N char of S1 and S2
 * @return 0 if S1 == S2
 * @return , -1 if S1 < S2
 * @return , 1 if S1 > S2
*/
int my_strncmp(const char *s1, const char *s2, int n);

/**
 * @brief Duplicates SRC and returns a pointer to duplicata
*/
char *my_strdup(char *src);

/**
 * @brief Duplicates N char of SRC and returns a pointer to duplicata
*/
char *my_strndup(char *src, int n);

/**
 * @brief Concatenates SRC at the end of DEST
*/
void my_strcat(char *dest, const char *src);

/**
 * @brief Concatenates N char of SRC at the end of DEST
*/
void my_strncat(char *dest, const char *src, int n);

/**
 * @brief Concatenates 1 char to DEST
*/
void my_strcat_char(char *dest, char src);

/**
 * @brief Returns a pointer to the first occurrence of TO_FIND in SRC
*/
char *my_strstr(char *src, char const *to_find);

/**
 * @brief Puts a file in a string and returns it
*/
char *get_file_in_string(char *filepath);

/**
 * @brief Checks if a file exists using stat and open
*/
int is_existing_file(char *filepath);

/**
 * @brief Returns if C is in STR
*/
int is_in(char c, char *str);

/**
 * @brief Returns if TO_FIND is in STR
*/
int is_str_in(char *str, char const *to_find);

/**
 * @brief Converts an int to a string
*/
char *int_to_str(int n);

/**
 * @brief Checks if STR is only composed of letters
*/
int my_str_isalpha(char const *str);

/**
 * @brief Checks if STR is only composed of numbers
*/
int my_str_isnum(char const *str);

/**
 * @brief Checks if STR is only composed of uppercase characters
*/
int my_str_isupper(char const *str);

/**
 * @brief Checks if STR is only composed of lowercase characters
*/
int my_str_islower(char const *str);

/*===---- arrays ----------------------------===
 *
 * all functions concerning arrays
 *
 ===-----------------------------------------===
 */

/**
 * @brief Calculate the lenght of ARRAY
*/
int my_arraylen(char **array);

/**
 * @brief Transforms STR to a string array based on giver separators
*/
char **my_str_to_word_array(char *str, char *separators);

/**
 * @brief Puts a file into a string array
*/
char **get_file_in_str_array(char *filepath);

/**
 * @brief Duplicates a string and returns a pointer to duplicata
*/
char **copy_array(char **array);

/**
 * @brief Frees ARRAY
*/
void free_array(char **array);

/**
 * @brief Sorts ARRAY on alphabetic order
*/
void my_sort_word_array(char **array, int size);

/**
 * @brief displays ARRAY in format [*line*]\n
*/
int my_show_word_array(char **tab);

char **str_to_arr(char *str, char sep);

#endif /* STR_H */
