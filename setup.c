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
    info->button_normal = sfTexture_createFromFile("ressources/start.png", NULL);
    info->button_test = sfTexture_createFromFile("exit.png", NULL);
    //info->button_hover = sfTexture_createFromFile("ressources/start_hover.png", NULL);
    info->test = sfTexture_createFromFile("ressources/trap.png", NULL);
    info->test_image = sfSprite_create();
    info->clock = sfClock_create();
}

void set_textures(info_t *info, scene_t *scene)
{
    info->zombie_rect.left = 0;
    info->zombie_rect.top = 0;
    info->zombie_rect.width = 60;
    info->zombie_rect.height = 70;

    sfSprite_setTexture(scene[0].background, info->menu_bg, sfFalse);
    sfSprite_setTexture(scene[1].background, info->game_bg, sfFalse);
    sfSprite_setTextureRect(scene[1].monster, info->zombie_rect);
    sfSprite_setTexture(scene[1].monster, info->zombie, sfFalse);
    sfSprite_setTexture(info->test_image, info->test, sfFalse);
}

scene_t *init_scenes(info_t *info)
{
    sfVector2f pos = {100, 100};
    sfVector2f size = {200, 100};
    sfVector2f pos2 = {300, 100};
    sfVector2f pos3 = {500, 100};
    scene_t *scene = malloc(sizeof(scene_t) * 5);

    scene[0].button = malloc(sizeof(button_t) * 3);
    for (int i = 0; i != 5; i++) {
        scene[i].background = sfSprite_create();
        scene[i].monster = sfSprite_create();
    }
    scene[1].button = malloc(sizeof(button_t) * 4);
    init_button(&scene[0].button[0], pos, size, info);
    scene[0].button[0].callback = &play;
    init_buttontwo(&scene[0].button[1], pos2, size, info);
    scene[0].button[1].callback = &exit_window;
    init_buttonthree(&scene[0].button[2], pos3, size, info);
    scene[0].button[2].callback = &exit_window;
    init_buttonpause(&scene[1].button[0], pos3, size, info);
    scene[1].button[0].callback = &put_in_pause;
    return(scene);
}

void init_button(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTextureRect(button->rect, info->start_rect);
}

void init_buttontwo(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_two = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_two, position);
    sfRectangleShape_setSize(button->rect_two, size);
    sfRectangleShape_setTexture(button->rect_two, info->button_test, 0);
}

void init_buttonthree(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_three = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_three, position);
    sfRectangleShape_setSize(button->rect_three, size);
    sfRectangleShape_setTexture(button->rect_three, info->button_test, 0);
}

void init_buttonpause(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_pause = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_pause, position);
    sfRectangleShape_setSize(button->rect_pause, size);
    sfRectangleShape_setTexture(button->rect_pause, info->button_test, 0);
}