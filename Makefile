##
## ZAPPY PROJECT, 2024
## zappy
## File description:
## Makefile
##

CD	=	cd

RMDIR	=	rm -rf

# ---------------------- DOCUMENTATION ---------------------------------- #

DOXYGEN = doxygen
DOC_DIR = ./documentation/
DOXYFILE = $(DOC_DIR)Doxyfile

# ----------------------------------------------------------------------- #

all:
	@$(CD) server && $(MAKE)
	@$(CD) ia && $(MAKE)
	@$(CD) graphical && $(MAKE)

clean:
	@$(CD) server && $(MAKE) clean
	@$(CD) ia && $(MAKE) clean
	@$(CD) graphical && $(MAKE) clean

fclean:
	@$(CD) server && $(MAKE) fclean
	@$(CD) ia && $(MAKE) fclean
	@$(CD) graphical && $(MAKE) fclean
	@$(CD) $(DOC_DIR) && $(RMDIR) docs/html

doc:
	@$(DOXYGEN) $(DOXYFILE) > /dev/null
	@printf "[\033[0;36mdoc built\033[0m]\n"

re:	fclean all

.PHONY: all clean fclean re