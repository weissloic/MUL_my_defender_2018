/*
** EPITECH PROJECT, 2018
** bootstrap_runner.c
** File description:
** bootstrap for my_runner
*/

#include "include/runner.h"

void game(player_t *player, info_t *info, scene_t *scene, button_t *button)
{
    sfVideoMode mode = {800, 600, 32};
    info->window = sfRenderWindow_create(mode, "jeu", sfResize | sfClose, NULL);
    info->view = 0;
    info->initial_parallax.x = 800;
    info->new_pos.x = 0;
    info->new_pos.y = 35;
    info->counter_turretone = 4;
    info->pos_turretone.x = 400;
    info->pos_turretone.y = 300;
    info->pos_turrettwo.x = 400;
    info->pos_turrettwo.y = 200;
    info->pos_menu.x = 500;
    info->pos_menu.y = 300;
    info->register_pos.x = 900;
    info->register_pos.y = 900;
    info->register_postwo.x = 900;
    info->register_postwo.y = 900;
    info->register_posthree.x = 900;
    info->register_posthree.y = 900;
    info->menu_turret = 0;
    info->zombie_rect.left = 0;
    info->zombie_rect.top = 0;
    info->zombie_rect.width = 60;
    info->zombie_rect.height = 70;
    info->shopmenu_pos.x = 0;
    info->shopmenu_pos.y = 400;
    info->money_pos.x = 155;
    info->money_pos.y = 510;
    info->shophouse_pos.x = 625;
    info->shophouse_pos.y = 0;
    info->seconds = sfClock_getElapsedTime(info->clock).SEC;

    sfRenderWindow_setVerticalSyncEnabled(info->window, sfTrue);
    set_textures(info, scene);

    sfMusic_setLoop(info->main_music, sfTrue);
    sfMusic_play(info->main_music);
    //my_loading_screen(info, scene);

    while (sfRenderWindow_isOpen(info->window)) {
        while (sfRenderWindow_pollEvent(info->window, &info->event)) {
            analyse_events(info, scene, button);
        }
        if (info->view == 1) {
            analyse_time(info);
            move_monster_time(info, scene);
            sfRenderWindow_drawSprite(info->window, scene[1].background, NULL);
            sfRenderWindow_drawSprite(info->window, scene[1].monster, NULL);
            sfRenderWindow_drawSprite(info->window, info->shopmenu, NULL);
            sfRenderWindow_drawSprite(info->window, info->dollar, NULL);


            if (info->menu_turret == 1) {
                scene[1].button[0].callback = &exit_turret_menu;
                info->pos_menu.x = 70;
                info->pos_menu.y = 70;
                sfSprite_setPosition(scene[1].turretone, info->pos_turretone);
                sfSprite_setPosition(scene[1].turrettwo, info->pos_turrettwo);
                sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
                sfRenderWindow_drawSprite(info->window, scene[1].turrettwo, NULL);
            }
            else {
                scene[1].button[0].callback = &coupe_decale;
                info->pos_menu.x = 300;
                info->pos_menu.y = 200; 
            }
            if (info->get_turret == 1) {
                create_turret(info, scene);
            }
            if (info->fill_turret == 1) {
                create_turrettwo(info, scene);
            }

            sfRectangleShape_setPosition(scene[1].button[0].rect_pause, info->pos_menu);
            sfRenderWindow_drawRectangleShape(info->window, scene[1].button[0].rect_pause, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[1].button[1].rect_shop, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[1].button[2].rect_putinpause, NULL);
            print_score(info);
        }
        if (info->view == 0) {
            parallax_main_menu(info, scene);
            sfRenderWindow_drawSprite(info->window, scene[0].background, NULL);
            sfRenderWindow_drawSprite(info->window, scene[0].background_mainmenu, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[0].button[0].rect, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[0].button[1].rect_two, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[0].button[2].rect_three, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[0].button[3].rect_four, NULL);
        }
        if (info->view == 2) {
            sfMusic_play(info->main_music);
            sfRenderWindow_drawSprite(info->window, scene[2].background, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[2].button[0].rect_turretone, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[2].button[1].rect_turrettwo, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[2].button[2].rect_turretthree, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[2].button[3].rect_turretfour, NULL);
            sfRenderWindow_drawSprite(info->window, info->shopmenu, NULL);
            sfRenderWindow_drawSprite(info->window, info->dollar, NULL);
            sfRenderWindow_drawSprite(info->window, info->shophouse, NULL);
            sfRenderWindow_drawText(info->window, info->turret_one, NULL);
            sfRenderWindow_drawText(info->window, info->turret_two, NULL);
            sfRenderWindow_drawText(info->window, info->turret_three, NULL);
            sfRenderWindow_drawText(info->window, info->nuke_price, NULL);
            print_score(info);
        }
        if (info->view == 4) {
            sfMusic_play(info->main_music);
            sfRenderWindow_drawSprite(info->window, scene[4].background, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[4].button[0].rect_pausresume, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[4].button[1].rect_pausbackmenu, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[4].button[2].rect_pausupsound, NULL);
            sfRenderWindow_drawSprite(info->window, info->pause_sprite, NULL);
        }
        sfRenderWindow_display(info->window);
        sfRenderWindow_clear(info->window, sfBlack);
    }
    destroy_music(info);
}

void create_turret(info_t *info, scene_t *scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f mouse_pos_float = {mouse_pos.x, mouse_pos.y};

    sfSprite_setPosition(scene[1].turretone, mouse_pos_float);
    sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
}

void create_turrettwo(info_t *info, scene_t *scene)
{
    sfSprite_setPosition(scene[1].turretone, info->register_pos);
    sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
    sfSprite_setPosition(scene[1].turretone, info->register_postwo);
    sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
    sfSprite_setPosition(scene[1].turretone, info->register_posthree);
    sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
}


void my_loading_screen(info_t *info, scene_t *scene)
{
    for (int i = 1; i != 180; i++) {
        for (int y = 0; y != 10; y++) {
            char *test = my_itoa(i);
            char str[] = "loadingscreen/sprite";
            char png[] = ".png";
            my_strcat(str, test);
            my_strcat(str, png);
            info->loadingscreen_bg = sfTexture_createFromFile(str, NULL);
            sfSprite_setTexture(scene[3].background, info->loadingscreen_bg, sfFalse);
            sfRenderWindow_drawSprite(info->window, scene[3].background, NULL);
            sfRenderWindow_display(info->window);
            if (i != 179)
                sfTexture_destroy(info->loadingscreen_bg);
        }
    }
    info->view = 0;
}


void analyse_time(info_t *info)
{
    float time = sfClock_getElapsedTime(info->score).SEC;

    if (time > 1) {
        info->score_int++;
        sfClock_restart(info->score);
    }
}

void move_monster_time(info_t *info, scene_t *scene)
{
    info->seconds = sfClock_getElapsedTime(info->clock).SEC;

    if (info->seconds > 0.01) {
        if (info->new_pos.x == 150 && info->new_pos.y == 40) {
            info->new_pos.y = 40;
            info->new_pos.x += 10;
        }
        else if (info->new_pos.x == 150) {
            info->new_pos.x = 150;
            info->new_pos.y += 2;
        }
        else
            info->new_pos.x += 2;
        sfSprite_setPosition(scene[1].monster, info->new_pos);
        sfClock_restart(info->clock);
    }
}

int main(int ac, char **av)
{
    player_t *player = malloc(sizeof(player_t));
    info_t *info = malloc(sizeof(info_t));
    scene_t *scene = init_scenes(info);
    button_t *button = malloc(sizeof(button_t));

    setup_textures(info);
    game(player, info, scene, button);
    return (0);
}