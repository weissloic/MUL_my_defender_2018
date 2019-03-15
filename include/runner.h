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
    sfVector2f initial_parallax;
    //GAME
    sfMusic *main_music;
    sfTexture *game_bg;
    sfTexture *loadingscreen_bg;
    sfTexture *zombie;
    sfTexture *simple_turret;
    sfTexture *double_turret;
    sfTexture *button_normal;
    sfTexture *button_hover;
    sfTexture *button_test;
    sfTexture *castle_texture;
    sfTexture *second_button_normal;
    sfTexture *second_button_hover;
    sfTexture *test;
    sfTexture *menu_shop;
    sfTexture *pause_texture;
    sfTexture *dollar_texture;
    sfTexture *shop_house;
    sfTexture *wall_texture;
    sfTexture *sign_price_texture;
    sfSprite *test_image;
    sfSprite *castle_sprite;
    sfSprite *dollar;
    sfSprite *shophouse;
    sfSprite *shopmenu;
    sfSprite *sign_price_sprite_1;
    sfSprite *sign_price_sprite_2;
    sfSprite *sign_price_sprite_3;
    sfSprite *sign_price_sprite_4;
    sfSprite *pause_sprite;
    sfClock *clock;
    sfIntRect zombie_rect;
    sfIntRect start_rect;
    int menu_turret;
    int counter_turretone;
    int get_turret;
    int switch_scene;
    sfVector2f pos_menu;
    sfVector2f temp_pos_for_menu;
    sfVector2f castle_position;
    sfVector2f sign_price_pos1;
    sfVector2f sign_price_pos2;
    sfVector2f sign_price_pos3;
    sfVector2f sign_price_pos4;
    //SCORE
    int score_int;
    sfClock *score;
    sfText *score_text;
    sfVector2f score_pos;
    sfVector2f money_pos;
    sfVector2f shophouse_pos;
    //SHOP
    sfTexture *nuke_logo;
    sfTexture *turret_one_logo;
    sfTexture *turret_two_logo;
    sfText *turret_one;
    sfText *turret_two;
    sfText *turret_three;
    sfText *nuke_price;
    sfVector2f register_pos;
    sfVector2f register_postwo;
    sfVector2f shopmenu_pos;
    sfVector2f register_posthree;
    int fill_turret;

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
    sfRectangleShape *rect_four;
    sfRectangleShape *rect_pause;
    sfRectangleShape *rect_shop;
    sfRectangleShape *rect_turretone;
    sfRectangleShape *rect_turrettwo;
    sfRectangleShape *rect_turretthree;
    sfRectangleShape *rect_turretfour;
    sfRectangleShape *rect_putinpause;
    sfRectangleShape *rect_gobackgame;
    sfRectangleShape *rect_pausupsound;
    sfRectangleShape *rect_pausresume;
    sfRectangleShape *rect_pausbackmenu;
    void (*callback)(info_t *info);
}button_t;

typedef struct  scene_s {
    struct  game_object_s *objs;
    struct  button_s *button;
    sfSprite *background;
    sfSprite *background_mainmenu;
    sfSprite *loadingscreen;
    sfSprite *monster;
    sfSprite *turretone;
    sfSprite *turrettwo;
}scene_t;

void game(player_t *, info_t *, scene_t *, button_t *);
void init_button(button_t *, sfVector2f, sfVector2f, info_t *);
sfVector2f manage_mouse_click(info_t *);
void analyse_events(info_t *, scene_t *, button_t *);
int button_is_clicked(button_t , sfVector2i);
void setup_textures(info_t *);
void set_textures(info_t *, scene_t *);
void move_monster_time(info_t *, scene_t *);
void play(info_t *);
void check_mouse_hovering(button_t, sfVector2i , info_t *i);
scene_t *init_scenes(info_t *);
void exit_window(info_t *);
char *my_itoa(int);
void my_loading_screen(info_t *, scene_t *);
void init_buttontwo(button_t *, sfVector2f, sfVector2f, info_t *);
int button_is_clicked(button_t, sfVector2i);
int button_is_clickedtwo(button_t, sfVector2i);
int button_is_clickedthree(button_t, sfVector2i);
void init_button(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttontwo(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonthree(button_t *, sfVector2f, sfVector2f, info_t *);
void check_mouse_hovering(button_t, sfVector2i, info_t *);
void check_mouse_hoveringtwo(button_t, sfVector2i, info_t *);
void check_mouse_hoveringthree(button_t, sfVector2i, info_t *);
void check_mouse_upgrademenu(button_t, sfVector2i, info_t *);
void init_buttonupgrade(button_t *, sfVector2f, sfVector2f, info_t *);
void analyse_time(info_t *);
void setup_score(info_t *);
void print_score(info_t *);
int button_is_clickedpause(button_t, sfVector2i);
void init_buttontower(button_t *, sfVector2f, sfVector2f, info_t *);
void move_towerbutton(info_t *);
void coupe_decale(info_t *);
void exit_turret_menu(info_t *);
char *my_strcat(char *, char *);
void init_buttonshop(button_t *, sfVector2f, sfVector2f, info_t *);
void goto_shopmenu(info_t *);
void goto_pausemenu(info_t *);
void setup_scene_0_buttons(scene_t *, info_t *);
void setup_scene_1_buttons(scene_t *, info_t *);
void setup_scene_2_buttons(scene_t *, info_t *);
void setup_scene_4_buttons(scene_t *, info_t *);
void check_mouse_shopmenu(button_t , sfVector2i , info_t *);
int button_is_clickedsound(button_t , sfVector2i);
int button_is_clickedbackmenu(button_t, sfVector2i);
int button_is_clickedresume(button_t, sfVector2i);
int button_buy_turretfour(button_t, sfVector2i);
int button_buy_turretthree(button_t, sfVector2i);
int button_buy_turrettwo(button_t, sfVector2i);
int button_buy_turretone(button_t, sfVector2i);
int button_is_clickedshop(button_t, sfVector2i);
int put_in_pausegame(button_t, sfVector2i);
void init_buttonturretone(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonturrettwo(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonturretthree(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonturretfour(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonptinpause(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonpauseresume(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonpausebackmenu(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonupsound(button_t *, sfVector2f, sfVector2f, info_t *);
void check_mouse_turrettwo(button_t, sfVector2i, info_t *);
void check_mouse_turretone(button_t, sfVector2i, info_t *);
void check_mouse_nukebutton(button_t, sfVector2i, info_t *);
void setup_price_nuke(info_t *);
void setup_price_turretthree(info_t *);
void setup_price_nuke(info_t *);
void setup_price_turrettwo(info_t *);
void setup_price_turretone(info_t *);
void setup_prices(info_t *);
void print_game(info_t *, scene_t *, button_t *, sfVector2i);
void print_menu(info_t *, scene_t *, button_t *, sfVector2i);
void print_pause_menu(info_t *, scene_t *, button_t *, sfVector2i);
void print_shop_menu(info_t *, scene_t *, button_t *, sfVector2i);
void positionning_turret(info_t *, sfVector2i);
void create_turret(info_t *, scene_t *);
void create_turrettwo(info_t *, scene_t *);
void create_music(info_t *);
void destroy_music(info_t *);
void goto_game(info_t *);
void parallax_main_menu(info_t *, scene_t *);
void check_gobacktogame(button_t, sfVector2i, info_t *);
void init_buttonwall(button_t *, sfVector2f, sfVector2f, info_t *);
void check_mouse_wall(button_t, sfVector2i, info_t *);
void setup_price_wall(info_t *);
void check_mouse_hoveringfour(button_t, sfVector2i, info_t *);
int button_is_clickedfour(button_t, sfVector2i);
int button_buy_wall(button_t, sfVector2i);
void check_mouse_pause(button_t, sfVector2i, info_t *);
int button_backtogame(button_t, sfVector2i);
void init_button_gobackgame(button_t *, sfVector2f, sfVector2f, info_t *);
void init_buttonfour(button_t *, sfVector2f, sfVector2f, info_t *);
void price_turretone(info_t *info);

#endif