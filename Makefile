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

SRC = src/game/game.c \
	  src/events/events.c \
	  src/setup/setup.c \
	  src/setup/my_itoa.c \
	  src/game/score.c \
	  src/ui/button.c \
	  src/events/callback.c \
	  src/game/pause.c \
	  src/ui/menu.c \
	  src/ui/shop.c \
	  src/game/game_in.c \
	  src/setup/music.c \
	  src/ui/parallax.c \

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
