/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void check_mouse_upgrademenu(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pause);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 80 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {

        info->start_rect.left = 520;
        info->start_rect.top = 165;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTextureRect(button.rect_pause, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pause, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 520;
        info->start_rect.top = 165;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTextureRect(button.rect_pause, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pause, info->second_button_normal, 0);
    }
}

int button_is_clickedpause(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pause);

    if (click_position.x >= button_pos.x + 80 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 80)
        return (1);
    else
        return (0);
}