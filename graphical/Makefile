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

NAME	=	zappy_gui

CXXFLAGS	=	-W -Wall -Wextra -std=c++20 -I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	@printf "\033[33mCompiling GUI...\033[0m\n"
	@$(CC) -o $(NAME) $(OBJ) > /dev/null 2>&1
	@$(MV) $(NAME) ../ > /dev/null 2>&1
	@printf "\033[32mGUI compiled and mooved succesfully !\033[0m\n"

clean:
	@printf "\033[33mCleaning object files for GUI...\033[0m\n"
	@$(RM) $(OBJ)

fclean:	clean
	@printf "\033[33mCleaning GUI binary...\033[0m\n"
	@$(CD) ../ && $(RM) $(NAME) > /dev/null 2>&1

re:	fclean all

.PHONY: all clean fclean re
