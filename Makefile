##
## ZAPPY PROJECT, 2024
## zappy
## File description:
## Makefile
##

CD	=	cd

# ---------------------- DOCUMENTATION ---------------------------------- #

DOXYGEN = doxygen
DOC_DIR = ./documentation/
DOXYFILE = $(DOC_DIR)Doxygen_conf

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

doc:
	@$(RM) -rf $(DOC_DIR)html
	@$(DOXYGEN) $(DOXYFILE) > /dev/null
	@printf "[\033[0;36mdoc built\033[0m]\n"
	@mv html $(DOC_DIR)

re:	fclean all

.PHONY: all clean fclean re