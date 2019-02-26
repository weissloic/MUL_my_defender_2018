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
    info->game_button = sfTexture_createFromFile("ressources/play.png", NULL);
}

void set_textures(info_t *info, scene_t *scene)
{
    sfSprite_setTexture(scene[0].background, info->menu_bg, sfFalse);
    sfSprite_setTexture(scene[1].background, info->game_bg, sfFalse);
    sfSprite_setTexture(scene[1].setting_button, info->game_button, sfFalse);
}

scene_t *init_scenes(info_t *info)
{
    sfVector2f pos = {100, 100};
    sfVector2f size = {200, 100};
    sfVector2f pos2 = {300, 100};
    scene_t *scene = malloc(sizeof(scene_t) * 3);

    scene[0].button = malloc(sizeof(button_t) * 2);
    for (int i = 0; i != 3; i++) {
        scene[i].background = sfSprite_create();
        scene[i].setting_button = sfSprite_create();
    }
    scene[1].button = malloc(sizeof(button_t) * 3);
    init_button(&scene[0].button[0], pos, size);
    scene[0].button[0].callback = &play;
    init_button(&scene[0].button[1], pos2, size);
    scene[0].button[1].callback = &exit_window;
    return(scene);
}

void init_button(button_t *button, sfVector2f position, sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setFillColor(button->rect, sfRed);
}