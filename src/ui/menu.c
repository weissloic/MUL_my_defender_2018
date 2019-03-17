/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void check_mouse_hoveringtwo(button_t button, sfVector2i mouse_pos,
info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_two);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        sfRectangleShape_setTexture(button.rect_two, info->button_hover, 0);
    }
    else {
        info->start_rect.left = 700;
        info->start_rect.top = 335;
        info->start_rect.width = 121;
        info->start_rect.height = 55;
        sfRectangleShape_setTextureRect(button.rect_two, info->start_rect);
        sfRectangleShape_setTexture(button.rect_two, info->button_normal, 0);
    }
}

void check_mouse_hoveringthree(button_t button, sfVector2i mouse_pos,
info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_three);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {
        sfRectangleShape_setTexture(button.rect_three,
        info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 300;
        info->start_rect.top = 140;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_three, info->start_rect);
        sfRectangleShape_setTexture(button.rect_three,
        info->second_button_normal, 0);
    }
}

void check_mouse_hoveringfour(button_t button, sfVector2i mouse_pos,
info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_four);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        info->start_rect.left = 523;
        info->start_rect.top = 165;
        info->start_rect.width = 121;
        info->start_rect.height = 55;
        sfRectangleShape_setTexture(button.rect_four, info->button_hover, 0);
    }
    else {
        info->start_rect.left = 523;
        info->start_rect.top = 168;
        info->start_rect.width = 121;
        info->start_rect.height = 55;
        sfRectangleShape_setTextureRect(button.rect_four, info->start_rect);
        sfRectangleShape_setTexture(button.rect_four, info->button_normal, 0);
    }
}
