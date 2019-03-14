/*
** EPITECH PROJECT, 2019
** setup.c
** File description:
** setup sprites and textures for defender
*/

#include "include/runner.h"

void setup_textures(info_t *info)
{
    info->menu_bg = sfTexture_createFromFile("ressources/back.png", NULL);
    info->game_bg = sfTexture_createFromFile("ressources/Grass1.png", NULL);
    info->zombie = sfTexture_createFromFile("ressources/zombie.png", NULL);
    info->button_normal = sfTexture_createFromFile("ressources/button2.png", NULL);
    info->button_hover = sfTexture_createFromFile("ressources/button3.png", NULL);
    info->second_button_normal = sfTexture_createFromFile("ressources/button1.png", NULL);
    info->second_button_hover = sfTexture_createFromFile("ressources/button4.png", NULL);
    info->simple_turret = sfTexture_createFromFile("ressources/simpleturret.png", NULL);
    info->double_turret = sfTexture_createFromFile("ressources/doubleturret.png", NULL);
    info->menu_shop = sfTexture_createFromFile("ressources/menu_shop.png", NULL);
    info->pause_texture = sfTexture_createFromFile("ressources/pause.png", NULL);
    info->dollar_texture = sfTexture_createFromFile("ressources/dollar.png", NULL);
    info->shop_house = sfTexture_createFromFile("ressources/shop_house.png", NULL);
    info->test_image = sfSprite_create();
    info->dollar = sfSprite_create();
    info->shophouse = sfSprite_create();
    info->shopmenu = sfSprite_create();
    info->pause_sprite = sfSprite_create();
    info->clock = sfClock_create();
    info->score = sfClock_create();
    setup_score(info);
    info->menu_turret = 0;
}

void set_textures(info_t *info, scene_t *scene)
{
    sfSprite_setTexture(scene[0].background, info->menu_bg, sfFalse);
    sfSprite_setTexture(scene[1].turretone, info->simple_turret, sfFalse);
    sfSprite_setTexture(scene[1].turrettwo, info->double_turret, sfFalse);
    sfSprite_setTexture(scene[1].background, info->game_bg, sfFalse);
    sfSprite_setTextureRect(scene[1].monster, info->zombie_rect);
    sfSprite_setTexture(scene[1].monster, info->zombie, sfFalse);
    sfSprite_setTexture(scene[2].background, info->game_bg, sfFalse);
    sfSprite_setTexture(scene[4].background, info->game_bg, sfFalse);
    sfSprite_setTexture(info->test_image, info->test, sfFalse);
    sfSprite_setTexture(info->dollar, info->dollar_texture, sfFalse);
    sfSprite_setTexture(info->shophouse, info->shop_house, sfFalse);
    sfSprite_setTexture(info->shopmenu, info->menu_shop, sfFalse);
    sfSprite_setTexture(info->pause_sprite, info->pause_texture, sfFalse);
    sfSprite_setPosition(info->shopmenu, info->shopmenu_pos);
    sfSprite_setPosition(info->dollar, info->money_pos);
    sfSprite_setPosition(info->shophouse, info->shophouse_pos);
}

void init_full_scene(scene_t *scene, info_t *info)
{
    for (int i = 0; i != 5; i++) {
        scene[i].background = sfSprite_create();
        scene[i].monster = sfSprite_create();
        scene[i].turretone = sfSprite_create();
        scene[i].turrettwo = sfSprite_create();
    }
}

void malloc_scene(info_t *info, scene_t *scene)
{
    scene[0].button = malloc(sizeof(button_t) * 3);
    scene[1].button = malloc(sizeof(button_t) * 4);
    scene[2].button = malloc(sizeof(button_t) * 4);
    scene[4].button = malloc(sizeof(button_t) * 4);
}

scene_t *init_scenes(info_t *info)
{

    scene_t *scene = malloc(sizeof(scene_t) * 5);


    malloc_scene(info, scene);
    init_full_scene(scene, info);
    setup_scene_0_buttons(scene, info);
    setup_scene_1_buttons(scene, info);
    setup_scene_2_buttons(scene, info);
    setup_scene_4_buttons(scene, info);

    //init_buttontower(&scene[1].button[1], pos, size, info);
    //scene[1].button[1].callback = &move_towerbutton;
    return(scene);
}

void setup_scene_0_buttons(scene_t *scene, info_t *info)
{
    sfVector2f size = {200, 100};
    sfVector2f pos2 = {300, 200};
    sfVector2f pos3 = {300, 300};
    sfVector2f pos = {300, 100};
    sfVector2f size2 = {90, 90};

    init_button(&scene[0].button[0], pos, size, info);
    scene[0].button[0].callback = &play;
    init_buttontwo(&scene[0].button[1], pos2, size, info);
    scene[0].button[1].callback = &exit_window;
    init_buttonthree(&scene[0].button[2], pos3, size2, info);
    scene[0].button[2].callback = &exit_window;
}

void setup_scene_1_buttons(scene_t *scene, info_t *info)
{
    sfVector2f pos_shop = {400, 0};
    sfVector2f pos_pause = {600, 200};
    sfVector2f size2 = {90, 90};

    init_buttonupgrade(&scene[1].button[0], info->pos_menu, size2, info);
    scene[1].button[0].callback = &coupe_decale;
    init_buttonshop(&scene[1].button[1], pos_shop, size2, info);
    scene[1].button[1].callback = &goto_shopmenu;
    init_buttonptinpause(&scene[1].button[2], pos_pause, size2, info);
    scene[1].button[2].callback = &goto_pausemenu;
}

void setup_scene_2_buttons(scene_t *scene, info_t *info)
{
    sfVector2f size2 = {90, 90};
    sfVector2f pos_buyturrettwo = {150, 300};
    sfVector2f pos_buyturretthree = {300, 300};
    sfVector2f pos_shop = {450, 300};
    sfVector2f pos_buyturretfour = {600, 300};

    init_buttonturretone(&scene[2].button[0], pos_shop, size2, info);
    scene[2].button[0].callback = &exit_window;
    init_buttonturrettwo(&scene[2].button[1], pos_buyturrettwo, size2, info);
    scene[2].button[1].callback = &exit_window;
    init_buttonturretthree(&scene[2].button[2], pos_buyturretthree, size2, info);
    scene[2].button[2].callback = &exit_window;
    init_buttonturretfour(&scene[2].button[3], pos_buyturretfour, size2, info);
    scene[2].button[3].callback = &exit_window;
}

void setup_scene_4_buttons(scene_t *scene, info_t *info)
{
    sfVector2f size2 = {90, 90};
    sfVector2f pos_buyturrettwo = {360, 240};
    sfVector2f pos_buyturretthree = {360, 360};
    sfVector2f pos_buyturretfour = {360, 480};

    init_buttonpauseresume(&scene[4].button[0], pos_buyturretfour, size2, info);
    scene[4].button[0].callback = &exit_window;
    init_buttonpausebackmenu(&scene[4].button[1], pos_buyturretthree, size2, info);
    scene[4].button[1].callback = &exit_window;
    init_buttonupsound(&scene[4].button[2], pos_buyturrettwo, size2, info);
    scene[4].button[2].callback = &exit_window;

}