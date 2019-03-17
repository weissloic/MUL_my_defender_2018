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
	  src/game/game2.c \
	  src/game/game3.c \
	  src/events/events.c \
	  src/events/events2.c \
	  src/events/events3.c \
	  src/events/events4.c \
	  src/events/events5.c \
	  src/setup/setup.c \
	  src/setup/setup2.c \
	  src/setup/setup3.c \
	  src/setup/my_itoa.c \
	  src/game/score.c \
	  src/game/score2.c \
	  src/ui/button.c \
	  src/events/callback.c \
	  src/events/callback2.c \
	  src/events/callback3.c \
	  src/events/callback4.c \
	  src/game/pause.c \
	  src/game/pause2.c \
	  src/game/pause3.c \
	  src/ui/menu.c \
	  src/ui/shop.c \
	  src/ui/shop2.c \
	  src/ui/shop3.c \
	  src/ui/shop4.c \
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
