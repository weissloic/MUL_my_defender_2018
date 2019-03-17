/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void init_button_gobackgame(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_gobackgame = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_gobackgame, position);
    sfRectangleShape_setSize(button->rect_gobackgame, size);
    sfRectangleShape_setTexture(button->rect_gobackgame, info->button_normal, 0);
}

int button_is_clickedshop(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_shop);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 50 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 50)
        return (1);
    else
        return (0);
}

int button_buy_turretone(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretone);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 70 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 80)
        return (1);
    else
        return (0);
}

int button_buy_turrettwo(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turrettwo);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 70 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 80)
        return (1);
    else
        return (0);
}

int button_backtogame(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_gobackgame);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 70 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 80)
        return (1);
    else
        return (0);
}