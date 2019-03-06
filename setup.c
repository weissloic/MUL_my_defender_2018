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
    info->zombie = sfTexture_createFromFile("ressources/zombie_above.png", NULL);
    info->button_normal = sfTexture_createFromFile("ressources/start_normal.png", NULL);
    info->button_test = sfTexture_createFromFile("ressources/start_normal.png", NULL);
    info->button_hover = sfTexture_createFromFile("ressources/start_hover.png", NULL);
    info->clock = sfClock_create();
}

void set_textures(info_t *info, scene_t *scene)
{
    sfSprite_setTexture(scene[0].background, info->menu_bg, sfFalse);
    sfSprite_setTexture(scene[1].background, info->game_bg, sfFalse);
    sfSprite_setTexture(scene[1].monster, info->zombie, sfFalse);
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
        scene[i].monster = sfSprite_create();
    }
    scene[1].button = malloc(sizeof(button_t) * 3);
    init_button(&scene[0].button[0], pos, size, info);
    scene[0].button[0].callback = &play;
    init_buttontwo(&scene[0].button[1], pos2, size, info);
    scene[0].button[1].callback = &exit_window;
    return(scene);
}

void init_button(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTexture(button->rect, info->button_normal, 0);
}

void init_buttontwo(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_two = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_two, position);
    sfRectangleShape_setSize(button->rect_two, size);
    sfRectangleShape_setTexture(button->rect_two, info->button_test, 0);
}