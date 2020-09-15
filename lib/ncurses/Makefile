##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CC	= g++

RM	= rm -f

NAME	=	lib_arcade_ncurses.so

CXXFLAGS 	= 	-I. -I./include -I ../../include

CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC -lncurses

SRCS	= 	src/Ncurses.cpp \
			src/GameObject.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJSEXE	= $(SRCSEXE:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		 $(CC) -shared $(OBJS) -o ../$(NAME) $(CXXFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re