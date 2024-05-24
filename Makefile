##
## ZAPPY PROJECT, 2024
## zappy
## File description:
## Makefile
##

CD	=	cd

RM	=	rm -f

all:
	$(CD) server && $(MAKE)
	$(CD) ia && $(MAKE)
	$(CD) graphical && $(MAKE)

clean:
	$(CD) server && $(MAKE) clean
	$(CD) ia && $(MAKE) clean
	$(CD) graphical && $(MAKE) clean

fclean:
	$(CD) server && $(MAKE) fclean
	$(CD) ia && $(MAKE) fclean
	$(CD) graphical && $(MAKE) fclean

re:	fclean all

.PHONY: all clean fclean re