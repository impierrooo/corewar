##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## base makefile
##

## -----------------
D = "\033[00m"
BOLD = "\e[1m"
RED = "\e[31m"
G = "\e[92m"
LB = "\e[94m"
WHITE = "\e[1;37m"
## -----------------

NAME    =   corewar

SRC	=	src/main.c

SRC += src/destroy/destroy_all.c
SRC += src/destroy/destroy_champs.c
SRC += src/destroy/destroy_corewar.c

SRC	+=	src/error_handling/check_number.c
SRC	+=	src/error_handling/check_structures.c
SRC	+=	src/error_handling/help.c
SRC	+=	src/error_handling/is_champion_path.c

SRC	+=	src/init/get_champion_instructions.c
SRC	+=	src/init/init_champions.c
SRC	+=	src/init/init_arena.c
SRC +=	src/init/init_corewar.c

SRC += src/parsing/check_params.c
SRC += src/parsing/getnbr_champs.c
SRC += src/parsing/set_address.c
SRC += src/parsing/set_dump.c
SRC += src/parsing/set_prog_number.c
SRC	+= src/parsing/get_header.c
SRC	+= src/parsing/check_instruction.c
SRC += src/parsing/get_index.c

SRC += src/instructions/exec_add.c
SRC += src/instructions/exec_aff.c
SRC += src/instructions/exec_and.c
SRC += src/instructions/exec_fork.c
SRC += src/instructions/exec_ld.c
SRC += src/instructions/exec_ldi.c
SRC += src/instructions/exec_lfork.c
SRC += src/instructions/exec_live.c
SRC += src/instructions/exec_lld.c
SRC += src/instructions/exec_lldi.c
SRC += src/instructions/exec_or.c
SRC += src/instructions/exec_st.c
SRC += src/instructions/exec_sti.c
SRC += src/instructions/exec_sub.c
SRC += src/instructions/exec_xor.c
SRC += src/instructions/exec_zjmp.c
SRC += src/instructions/get_params.c

SRC	+= src/corewar.c
SRC	+= src/htobe.c
SRC	+= src/get_param_size.c
SRC	+= src/hex_to_int.c
SRC += src/hexa_to_bin.c

OBJS    = 	$(SRC:.c=.o)

LFLAGS  =   -L./lib/ -lmy

IFLAGS  =   -I./include/

CFLAGS	+=	-Wall -Wextra -g $(IFLAGS)

all:    $(NAME)

$(NAME):        $(OBJS)
	@ make -C ./lib/ --no-print-directory
	@ $(CC) -o$(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	@ $(CC) $(CFLAGS) -c -o $@ $< && \
	echo -e $(BOLD) $(G) " [OK]" $(D) $(LG) $< $(D) || \
	echo -e $(BOLD) $(RED) " [KO]" $(D) $(LG) $< $(D)

debug:			$(OBJS)
	@ make -C ./lib/ --no-print-directory
	@ $(CC) -o$(NAME) $(OBJS) $(LFLAGS)

lib:
	@ make fclean -C ./lib/ --no-print-directory
	@ make -C ./lib/ --no-print-directory

clean:
	@ rm -f *.gc* && echo -e $(BOLD) $(LB) "  [clean]" $(D) $(LG)
	@ rm -f $(OBJS)

fclean: clean
	@ rm -f $(NAME) && echo -e $(BOLD) $(LB) "  [fclean]" $(D) $(LG)

re: fclean $(NAME)

.PHONY: all $(NAME) clean fclean re lib
