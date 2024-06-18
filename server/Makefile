##
## ZAPPY PROJECT, 2024
## zappy
## File description:
## Makefile
##

CC	=	gcc

CD	=	cd

MV 	=	mv

SRC = $(shell find src -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

CFLAGS	=	-W -Wall -Wextra -Werror -I ./include

GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
YELLOW	=	\033[0;35m
CYAN	=	\033[1;36m
RC 		= 	\033[0m

PRINTER	=	printf "$(BLUE)$(NAME) ▷ $(RC)" ; printf

all: $(NAME)

$(NAME): prebuild $(OBJ)
	@ $(PRINTER) "$(YELLOW)%-40b" "Building $(NAME)"
	@ $(CC) -o $(NAME) $(OBJ) && \
	  (printf "$(GREEN)Done$(RC)\n") && $(MV) $(NAME) ../ || \
	  (printf "$(RED)Fail\n")
	@ printf "\033[32mServer compiled and mooved succesfully !\033[0m\n"

prebuild:
	@ $(PRINTER) "$(YELLOW)%b\n" "Compiling files"

.c.o:
	@ $(CC) -c $< -o $@ $(CFLAGS) && \
	  (printf "$(CYAN) %b $(GREEN)「✔」$(RC)\n" $<) || \
	  (printf "$(CYAN) %b $(RED)[XX] $(RC)\n" $< ; exit 1)

clean:
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean server files"
	@ $(RM) $(OBJ)
	@ printf "$(GREEN)Done$(RC)\n"

fclean: clean
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean $(BINARY)$(RC)"
	@ $(CD) ../ && $(RM) $(NAME)
	@ printf "$(GREEN)Done$(RC)\n"

re: fclean all

.PHONY: all clean fclean re
