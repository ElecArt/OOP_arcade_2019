##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

.PHONY: all games graphicals clean fclean re
all: games graphicals core

games:
	make -C ./games/snake
	make -C ./games/pacman

core:
	make -C ./src/

graphicals:
	make -C ./lib/ncurses/
	make -C ./lib/sfml/
	make -C ./lib/allegro/

clean:
	make clean -C ./lib/ncurses/
	make clean -C ./lib/sfml/
	make clean -C ./lib/allegro/
	make clean -C ./src/
	make clean -C ./games/snake/
	make clean -C ./games/pacman/

fclean:
	make fclean -C ./lib/ncurses/
	make fclean -C ./lib/sfml/
	make fclean -C ./lib/allegro/
	make fclean -C ./src/
	make fclean -C ./games/snake/
	make fclean -C ./games/pacman/

re: fclean all