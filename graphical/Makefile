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

LDFLAGS += -lsfml-graphics -lsfml-window -lsfml-system

PRINTER	=	printf "$(BLUE)$(PROJECT) ▷ " ; printf

GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
YELLOW	=	\033[0;35m
CYAN	=	\033[1;36m

all: $(BINARY)

$(BINARY): prebuild $(OBJS)
	@ $(PRINTER) "$(YELLOW)%-40b" "Building $(PROJECT)"
	@ $(CXX) -o $(BINARY) $(OBJS) $(LDFLAGS) && \
	  (printf "$(GREEN)Done\n" ; exit 0) || \
	  (printf "$(RED)Fail\n" ; exit 1)

prebuild:
	@ $(PRINTER) "$(YELLOW)%b\n" "Compiling files"

clean:
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean files"
	@ rm -f $(OBJS)
	@ printf "$(GREEN)Done\n"

fclean: clean
	@ $(PRINTER) "$(YELLOW)%-40b" "Clean $(BINARY)"
	@ rm -f $(BINARY)
	@ printf "$(GREEN)Done\n"

re: fclean all

.cpp.o:
	@ $(CXX) -c $< -o $@ $(CFLAGS) && \
	  (printf "$(CYAN) %b $(GREEN)「✔」\n" $<) || \
	  (printf "$(CYAN) %b $(RED)[XX]\n" $< ; exit 1)

.PHONY: all $(BINARY) prebuild clean fclean re .cpp.o