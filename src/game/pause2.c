/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

int button_is_clickedbackmenu(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pausbackmenu);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

void check_mouse_pause(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_putinpause);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {

        sfRectangleShape_setTexture(button.rect_putinpause, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 580;
        info->start_rect.top = 80;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_putinpause, info->start_rect);
        sfRectangleShape_setTexture(button.rect_putinpause, info->second_button_normal, 0);
    }
}

void check_mouse_resume(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pausresume);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {

        sfRectangleShape_setTexture(button.rect_pausresume, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 63;
        info->start_rect.top = 0;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_pausresume, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pausresume, info->second_button_normal, 0);
    }
}

void check_mouse_backmenu(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pausbackmenu);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {

        sfRectangleShape_setTexture(button.rect_pausbackmenu, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 435;
        info->start_rect.top = 140;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_pausbackmenu, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pausbackmenu, info->second_button_normal, 0);
    }
}

void check_mouse_exitgame(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pausupsound);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {

        sfRectangleShape_setTexture(button.rect_pausupsound, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 360;
        info->start_rect.top = 310;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_pausupsound, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pausupsound, info->second_button_normal, 0);
    }
}