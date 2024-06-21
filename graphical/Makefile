##
## ZAPPY PROJECT, 2024
## delivery
## File description:
## Makefile
##

PROJECT	=	Zappy_GUI

BINARY	=	zappy_gui

CXX	?=	g++

OBJS	=	$(SRCS:.cpp=.o)

SRCS	=	$(shell find ./ -name '*.cpp')

CFLAGS	+=	-Wall -Wextra -Werror
CPPFLAGS	+=	-I ./include -std=c++17

LDFLAGS += -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
YELLOW	=	\033[0;35m
CYAN	=	\033[1;36m
RC 		= 	\033[0m

PRINTER	=	printf "$(BLUE)$(PROJECT) ▷ $(RC)" ; printf

all: $(BINARY)

$(BINARY): prebuild $(OBJS)
	@ $(PRINTER) "$(YELLOW)%-40b" "Building $(PROJECT)"
	@ $(CXX) -o $(BINARY) $(OBJS) $(LDFLAGS) && \
	  (printf "$(GREEN)Done$(RC)\n") && mv $(BINARY) ../ || \
	  (printf "$(RED)Fail\n")
	@ printf "\033[32mGRAPHICAL compiled and mooved succesfully !\033[0m\n"

prebuild:
	@ $(PRINTER) "$(YELLOW)%b\n" "Compiling files"

.cpp.o:
	@ $(CXX) -c $< -o $@ $(CFLAGS) $(CPPFLAGS) && \
	  (printf "$(CYAN) %b $(GREEN)「✔」$(RC)\n" $<) || \
	  (printf "$(CYAN) %b $(RED)[XX] $(RC)\n" $< ; exit 1)

clean:
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean graphical files"
	@ rm -f $(OBJS)
	@ printf "$(GREEN)Done$(RC)\n"

fclean: clean
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean $(BINARY)$(RC)"
	@ rm -f ../$(BINARY)
	@ printf "$(GREEN)Done$(RC)\n"

re: fclean all

.PHONY: all $(BINARY) prebuild clean fclean re .cpp.o
