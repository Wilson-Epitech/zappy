##
## ZAPPY PROJECT, 2024
## zappy
## File description:
## Makefile
##

CC	=	g++

CD	=	cd

MV 	=	mv

SRC = $(shell find src -name '*.cpp')

OBJ	=	$(SRC:.cpp=.o)

NAME	=	zappy_ai

CXXFLAGS	=	-W -Wall -Wextra -Werror -std=c++20 -I ./include

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
	@ printf "\033[32mIA compiled and mooved succesfully !\033[0m\n"

prebuild:
	@ $(PRINTER) "$(YELLOW)%b\n" "Compiling files"

.cpp.o:
	@ $(CC) -c $< -o $@ $(CXXFLAGS) && \
	  (printf "$(CYAN) %b $(GREEN)「✔」$(RC)\n" $<) || \
	  (printf "$(CYAN) %b $(RED)[XX] $(RC)\n" $< ; exit 1)

clean:
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean IA files"
	@ $(RM) $(OBJ)
	@ printf "$(GREEN)Done$(RC)\n"

fclean: clean
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean $(BINARY)$(RC)"
	@ $(CD) ../ && $(RM) $(NAME)
	@ printf "$(GREEN)Done$(RC)\n"

re: fclean all

.PHONY: all clean fclean re
