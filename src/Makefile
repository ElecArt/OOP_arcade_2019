##
## EPITECH PROJECT, 2020
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

CC	= g++

RM	= rm -f

NAME		=	arcade

CFLAGS	= -W -Wall -Wextra

CXXFLAGS 	= 	-I. -I ../include

SRCS	=	main.cpp	\
			Core.cpp	\
			States/MenuState.cpp \
			States/GameState.cpp \
			States/ScoreState.cpp \
			States/GameOverState.cpp \
			States/HelpState.cpp	\
			Engine/State.cpp \
			Engine/StateMachine.cpp

OBJS	= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):		$(OBJS)
		$(CC) $(OBJS) -o ./../$(NAME) -ldl

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) ./../$(NAME)

re: fclean all

.PHONY: all clean fclean re