/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button
*/

#include "include/runner.h"

void init_buttonupgrade(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_pause = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect_pause, size);
    sfRectangleShape_setTexture(button->rect_pause, info->second_button_normal, 0);
}

void init_buttontower(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfRed);
}

int button_is_clickedtower(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}