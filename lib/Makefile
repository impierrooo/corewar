##
## EPITECH PROJECT, 2023
## B-CPE-110-REN-1-1-organized-pierre.marguerie
## File description:
## Makefile
##

## -----------------
D = "\033[00m"
BOLD = "\e[1m"
RED = "\e[31m"
GREEN = "\e[32m"
LB = "\e[94m"
WHITE = "\e[1;37m"
## -----------------

NAME 	=	libmy.a

SRC		=   src/number/my_compute_square_root.c
SRC		+=   src/number/my_find_prime_sup.c
SRC		+=   src/number/my_getnbr.c
SRC		+=   src/number/my_is_prime.c
SRC		+=   src/number/my_isneg.c
SRC		+=   src/number/my_sort_int_array.c
SRC		+=   src/number/my_swap.c
SRC		+=   src/number/power.c

SRC		+=	src/puts/pf/handles/handle_c.c
SRC		+=	src/puts/pf/handles/handle_d.c
SRC		+=	src/puts/pf/handles/handle_e.c
SRC		+=	src/puts/pf/handles/handle_emaj.c
SRC		+=	src/puts/pf/handles/handle_f.c
SRC		+=	src/puts/pf/handles/handle_fmaj.c
SRC		+=	src/puts/pf/handles/handle_g.c
SRC		+=	src/puts/pf/handles/handle_gmaj.c
SRC		+=	src/puts/pf/handles/handle_i.c
SRC		+=	src/puts/pf/handles/handle_n.c
SRC		+=	src/puts/pf/handles/handle_o.c
SRC		+=	src/puts/pf/handles/handle_p.c
SRC		+=	src/puts/pf/handles/handle_percent.c
SRC		+=	src/puts/pf/handles/handle_s.c
SRC		+=	src/puts/pf/handles/handle_u.c
SRC		+=	src/puts/pf/handles/handle_x.c
SRC		+=	src/puts/pf/handles/handle_xmaj.c

SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/converter_g.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/converter_gmaj.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_float.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_long_float.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_nbr_plus.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_nbr_scientific_e.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_nbr_scientific_emaj.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_nbr_space.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_short.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_unsigned_int.c
SRC		+=	src/puts/pf/put_funcs/put_nbr_funcs/my_put_unsigned_short.c

SRC		+=	src/puts/pf/put_funcs/my_put_ptr.c
SRC		+=	src/puts/pf/put_funcs/my_putnbr_base.c

SRC		+=	src/puts/pf/display_funcs.c
SRC		+=	src/puts/pf/my_parser.c
SRC		+=	src/puts/pf/my_printf.c

SRC		+=	src/puts/my_put_nbr.c
SRC		+=	src/puts/my_putchar.c
SRC		+=	src/puts/my_putstr.c

SRC		+= 	 src/str/get_file_in_array.c
SRC		+=	 src/str/int_to_str.c
SRC		+=   src/str/is_in.c
SRC		+=   src/str/my_revstr.c
SRC		+=   src/str/my_show_word_array.c
SRC		+=	 src/str/my_str_to_word_array.c
SRC		+=   src/str/my_sort_word_array.c
SRC		+=   src/str/my_strcat.c
SRC		+=   src/str/my_strcmp.c
SRC		+=   src/str/my_strcpy.c
SRC		+=   src/str/my_strdup.c
SRC		+=   src/str/my_strisalpha.c
SRC		+=   src/str/my_strislower.c
SRC		+=   src/str/my_strisnum.c
SRC		+=   src/str/my_strisupper.c
SRC		+=   src/str/my_strlen.c
SRC		+=   src/str/my_strlowcase.c
SRC		+=   src/str/my_strstr.c
SRC		+=   src/str/my_strupcase.c
SRC		+=	src/str/is_existing_file.c
SRC		+=	src/str/my_arraylen.c
SRC		+=	src/str/copy_array.c
SRC		+=	src/str/free_array.c

OBJS	=	$(SRC:.c=.o)

IFLAGS	=	-I./include/

CFLAGS	+=	-Wall -Wextra $(IFLAGS)

all:    $(NAME)

$(NAME): $(OBJS)
	@ ar rc $(NAME) $(OBJS)
	@ cp include/my_printf.h include/my.h include/str.h ../include/

%.o: %.c
	@ $(CC) $(CFLAGS) -c -o $@ $< && \
	echo -e $(BOLD) $(GREEN) "[OK]" $(D) $(LG) $< $(D) || \
	echo -e $(BOLD) $(GREEN) "[KO]" $(D) $(LG) $< $(D)

clean:
	@ rm -f *.gc* && echo -e $(BOLD) $(LB) "[lib clean]" $(D) $(LG)
	@ rm -f $(OBJS)

fclean: clean
	@ rm -f $(NAME) && echo -e $(BOLD) $(LB) "[lib fclean]" $(D) $(LG)

re: fclean $(NAME)

.PHONY: all $(NAME) clean fclean re
