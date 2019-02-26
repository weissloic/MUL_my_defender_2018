/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#ifndef RUNNER_H_
#define RUNNER_H_
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SEC microseconds / 1000000.f

typedef struct player {
    sfTexture *main_base;
    sfSprite *base;
    int points;
}player_t;

typedef struct game_info {
    sfRenderWindow *window;
    sfEvent event;
    //MENU
    sfTexture *menu_bg;
    //GAME
    sfTexture *game_bg;
    sfTexture *game_button;
    int view;
}info_t;

typedef struct button_s {
    sfRectangleShape *rect;
    void (*callback)(info_t *info);
}button_t;

typedef struct  scene_s {
    struct  game_object_s *objs;
    struct  button_s *button;
    sfSprite *background;
    sfSprite *setting_button;
}scene_t;

void game(player_t *player, info_t *info, scene_t *scene, button_t *button);
void init_button(button_t *button, sfVector2f position, sfVector2f size);
sfVector2f manage_mouse_click(info_t *info);
void analyse_events(info_t *info, scene_t *scene, button_t *button);
int button_is_clicked(button_t button, sfVector2i click_position);
void setup_textures(info_t *info);
void set_textures(info_t *info, scene_t *scene);

#endif
