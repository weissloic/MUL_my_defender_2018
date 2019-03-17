/*
** EPITECH PROJECT, 2019
** setup.c
** File description:
** setup sprites and textures for defender
*/

#include "../../include/runner.h"

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
    info->nuke_logo = sfTexture_createFromFile("ressources/logonuclear.png", NULL);
    info->turret_one_logo = sfTexture_createFromFile("ressources/simpleturret.png", NULL);
    info->turret_two_logo = sfTexture_createFromFile("ressources/doubleturret.png", NULL);
    info->castle_texture = sfTexture_createFromFile("ressources/castle.png", NULL);
    info->wall_texture = sfTexture_createFromFile("ressources/wall.png", NULL);
    setup_texturestwo(info);
}

void set_textures(info_t *info, scene_t *scene)
{
    sfSprite_setTexture(scene[0].background, info->menu_bg, sfFalse);
    sfSprite_setTexture(scene[0].background_mainmenu, info->menu_bg, sfFalse);
    sfSprite_setTexture(scene[1].turretone, info->simple_turret, sfFalse);
    sfSprite_setTexture(scene[1].turrettwo, info->double_turret, sfFalse);
    sfSprite_setTexture(scene[1].turretthree,
    info->wall_textureresize, sfFalse);
    sfSprite_setTexture(scene[1].background, info->game_bg, sfFalse);
    sfSprite_setTextureRect(scene[1].monster, info->zombie_rect);
    sfSprite_setTexture(scene[1].monster, info->zombie, sfFalse);
    sfSprite_setTexture(scene[2].background, info->game_bg, sfFalse);
    set_texturestwo(info, scene);
}

void init_full_scene(scene_t *scene, info_t *info)
{
    for (int i = 0; i != 5; i++) {
        scene[i].background = sfSprite_create();
        scene[i].monster = sfSprite_create();
        scene[i].turretone = sfSprite_create();
        scene[i].turrettwo = sfSprite_create();
        scene[i].turretthree = sfSprite_create();
    }
    scene[0].background_mainmenu = sfSprite_create();
}

void malloc_scene(info_t *info, scene_t *scene)
{
    scene[0].button = malloc(sizeof(button_t) * 4);
    scene[1].button = malloc(sizeof(button_t) * 4);
    scene[2].button = malloc(sizeof(button_t) * 5);
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
    return(scene);
}