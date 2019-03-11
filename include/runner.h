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
    sfTexture *loadingscreen_bg;
    sfTexture *zombie;
    sfTexture *simple_turret;
    sfTexture *double_turret;
    sfTexture *button_normal;
    sfTexture *button_hover;
    sfTexture *button_test;
    sfTexture *second_button_normal;
    sfTexture *second_button_hover;
    sfTexture *test;
    sfSprite *test_image;
    sfClock *clock;
    sfIntRect zombie_rect;
    sfIntRect start_rect;
    int menu_turret;
    sfVector2f pos_menu;
    sfVector2f temp_pos_for_menu;
    //SCORE
    int score_int;
    sfClock *score;
    sfText *score_text;
    sfVector2f score_pos;
    sfFont *font;
    float seconds;
    int view;
    sfVector2f new_pos;
    sfVector2f pos_turretone;
    sfVector2f pos_turrettwo;
}info_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfRectangleShape *rect_two;
    sfRectangleShape *rect_three;
    sfRectangleShape *rect_pause;
    sfRectangleShape *rect_shop;
    void (*callback)(info_t *info);
}button_t;

typedef struct  scene_s {
    struct  game_object_s *objs;
    struct  button_s *button;
    sfSprite *background;
    sfSprite *loadingscreen;
    sfSprite *monster;
    sfSprite *turretone;
    sfSprite *turrettwo;
}scene_t;

void game(player_t *player, info_t *info, scene_t *scene, button_t *button);
void init_button(button_t *button, sfVector2f position, sfVector2f size, info_t *info);
sfVector2f manage_mouse_click(info_t *info);
void analyse_events(info_t *info, scene_t *scene, button_t *button);
int button_is_clicked(button_t button, sfVector2i click_position);
void setup_textures(info_t *info);
void set_textures(info_t *info, scene_t *scene);
void move_monster_time(info_t *, scene_t *);
void play(info_t *info);
void check_mouse_hovering(button_t button, sfVector2i mouse_pos, info_t *info);
scene_t *init_scenes(info_t *info);
void exit_window(info_t *info);
void put_in_pause(info_t *info);
char *my_itoa(int nb);
void my_loading_screen(info_t *, scene_t *);
void init_buttontwo(button_t *button, sfVector2f position, sfVector2f size, info_t *info);
int button_is_clicked(button_t button, sfVector2i click_position);
int button_is_clickedtwo(button_t button, sfVector2i click_position);
int button_is_clickedthree(button_t button, sfVector2i click_position);
void init_button(button_t *button, sfVector2f position, sfVector2f size, info_t *info);
void init_buttontwo(button_t *button, sfVector2f position, sfVector2f size, info_t *info);
void init_buttonthree(button_t *button, sfVector2f position, sfVector2f size, info_t *info);
void check_mouse_hovering(button_t button, sfVector2i mouse_pos, info_t *info);
void check_mouse_hoveringtwo(button_t button, sfVector2i mouse_pos, info_t *info);
void check_mouse_hoveringthree(button_t button, sfVector2i mouse_pos, info_t *info);
void check_mouse_upgrademenu(button_t button, sfVector2i mouse_pos, info_t *info);
void init_buttonupgrade(button_t *button, sfVector2f position, sfVector2f size, info_t *info);
void analyse_time(info_t *info);
void setup_score(info_t *info);
void print_score(info_t *info);
int button_is_clickedpause(button_t button, sfVector2i click_position);
void init_buttontower(button_t *button, sfVector2f position, sfVector2f size, info_t *info);
void move_towerbutton(info_t *info);
void coupe_decale(info_t *info);
void exit_turret_menu(info_t *info);
char *my_strcat(char *, char *);
void init_buttonshop(button_t *button, sfVector2f position, sfVector2f size, info_t *info);

#endif
