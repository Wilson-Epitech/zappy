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

CXXFLAGS	+=	-Wall
CXXFLAGS	+=	-Wextra
CXXFLAGS	+=	-Werror
CXXFLAGS	+=	-O2
CXXFLAGS	+=	-std=c++17
CXXFLAGS	+=	-I ./include

LDFLAGS += -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

PRINTER	=	printf "$(BLUE)$(PROJECT) ▷ $(RC)" ; printf

GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
YELLOW	=	\033[0;35m
CYAN	=	\033[1;36m
RC 		= 	\033[0m

all: $(BINARY)

$(BINARY): prebuild $(OBJS)
	@ $(PRINTER) "$(YELLOW)%-40b" "Building $(PROJECT)"
	@ $(CXX) -o $(BINARY) $(OBJS) $(LDFLAGS) && \
	  (printf "$(GREEN)Done$(RC)\n") && mv $(BINARY) ../ || \
	  (printf "$(RED)Fail\n")

prebuild:
	@ $(PRINTER) "$(YELLOW)%b\n" "Compiling files"

clean:
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean files"
	@ rm -f $(OBJS)
	@ printf "$(GREEN)Done$(RC)\n"

fclean: clean
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean $(BINARY)$(RC)"
	@ rm -f ../$(BINARY)
	@ printf "$(GREEN)Done$(RC)\n"

re: fclean all

.cpp.o:
	@ $(CXX) -c $< -o $@ $(CFLAGS) && \
	  (printf "$(CYAN) %b $(GREEN)「✔」$(RC)\n" $<) || \
	  (printf "$(CYAN) %b $(RED)[XX] $(RC)\n" $< ; exit 1)

.PHONY: all $(BINARY) prebuild clean fclean re .cpp.o
