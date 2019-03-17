/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

int button_buy_wall(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos;
    button_pos = sfRectangleShape_getPosition(button.rect_turretthree);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_buy_turretfour(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos;
    button_pos = sfRectangleShape_getPosition(button.rect_turretfour);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

void setup_prices(info_t *info)
{
    setup_price_turretone(info);
    setup_price_turrettwo(info);
    setup_price_wall(info);
    setup_price_nuke(info);
}