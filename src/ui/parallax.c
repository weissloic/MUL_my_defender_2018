/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** parallax
*/

#include "../../include/runner.h"

void parallax_main_menu(info_t *info, scene_t *scene)
{
    sfVector2f back = sfSprite_getPosition(scene[0].background);
    sfVector2f back2 = sfSprite_getPosition(scene[0].background_mainmenu);

    back.x = back.x - 2;
    back2.x = back2.x - 2;
    sfSprite_setPosition(scene[0].background, back);
    sfSprite_setPosition(scene[0].background_mainmenu, back2);
    if (back.x <= -800)
        sfSprite_setPosition(scene[0].background, info->initial_parallax);
    if (back2.x <= -800)
        sfSprite_setPosition(scene[0].background_mainmenu,
        info->initial_parallax);
}

void init_button(button_t *button, sfVector2f position,
sfVector2f size, info_t *info)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTextureRect(button->rect, info->start_rect);
}

void init_buttontwo(button_t *button, sfVector2f position,
sfVector2f size, info_t *info)
{
    button->rect_two = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_two, position);
    sfRectangleShape_setSize(button->rect_two, size);
    sfRectangleShape_setTexture(button->rect_two, info->button_normal, 0);
}

void init_buttonthree(button_t *button, sfVector2f position,
sfVector2f size, info_t *info)
{
    button->rect_three = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_three, position);
    sfRectangleShape_setSize(button->rect_three, size);
    sfRectangleShape_setTexture(button->rect_three, info->button_normal, 0);
}

void init_buttonfour(button_t *button, sfVector2f position,
sfVector2f size, info_t *info)
{
    button->rect_four = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_four, position);
    sfRectangleShape_setSize(button->rect_four, size);
    sfRectangleShape_setTexture(button->rect_four, info->button_normal, 0);
}