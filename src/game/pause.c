/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

int put_in_pausegame(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos;
    button_pos = sfRectangleShape_getPosition(button.rect_putinpause);

    if (click_position.x >= button_pos.x && 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_is_clickedresume(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos;
    button_pos = sfRectangleShape_getPosition(button.rect_pausresume);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_is_clickedsound(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos;
    button_pos = sfRectangleShape_getPosition(button.rect_pausupsound);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}