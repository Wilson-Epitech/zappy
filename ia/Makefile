##
## ZAPPY PROJECT, 2024
## zappy
## File description:
## Makefile
##

CC	=	g++

CD	=	cd

MV	=	mv

SRC = $(shell find src -name '*.cpp')

OBJ	=	$(SRC:.cpp=.o)

NAME	=	zappy_ai

CXXFLAGS	=	-W -Wall -Wextra -std=c++20 -I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	@printf "\033[33mCompiling IA...\033[0m\n"
	@$(CC) -o $(NAME) $(OBJ) > /dev/null 2>&1
	@$(MV) $(NAME) ../ > /dev/null 2>&1
	@printf "\033[32mIA compiled and mooved succesfully !\033[0m\n"

clean:
	@$(RM) $(OBJ) > /dev/null 2>&1
	@printf "\033[33mCleaning object files for IA...\033[0m\n"

fclean:	clean
	@$(CD) ../ && $(RM) $(NAME) > /dev/null 2>&1
	@printf "\033[33mCleaning IA binary...\033[0m\n"


re:	fclean all

.PHONY: all clean fclean re
