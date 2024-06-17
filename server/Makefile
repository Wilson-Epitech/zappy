##
## ZAPPY PROJECT, 2024
## zappy
## File description:
## Makefile
##

CC	=	gcc

CD	=	cd

MV	=	mv

SRC = $(shell find src -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

CFLAGS	=	-W -Wall -Wextra -I ./include -g3

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\033[33mCompiling Server...\033[0m\n"
	@$(CC) -o $(NAME) $(OBJ)
	@$(MV) $(NAME) ../
	@printf "\033[32mServer compiled and mooved succesfully !\033[0m\n"

clean:
	@printf "\033[33mCleaning object files for server...\033[0m\n"
	@$(RM) $(OBJ)

fclean: clean
	@printf "\033[33mCleaning server binary...\033[0m\n"
	@$(CD) ../ && $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
