##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

CC = gcc -g -Wall

RM = rm -f

LIB = ar rc

MY = my.h

SRC = game.c \
	  events.c \
	  setup.c \
	  my_itoa.c \
	  score.c \
	  button.c \
	  callback.c \
	  pause.c \
	  menu.c \
	  shop.c \
	  game_in.c


OBJ = $(SRC:.c = .o)

NAME = my_defender

all: $(NAME)

$(NAME):
	@make -sC ./lib/my all
	@$(CC) -o $(NAME) $(OBJ) -I.include/ -lcsfml-graphics -lcsfml-system -Llib/my -lmy -lcsfml-audio -lcsfml-window

clean:
	@$(RM) *~

fclean: clean
	@make -sC ./lib/my fclean
	@rm -f $(NAME)

re: fclean all
