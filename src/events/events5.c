/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "../../include/runner.h"

void check_mouse_turretone(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretone);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretone, info->turret_one_logo, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretone, info->turret_one_logo, 0);
    }
}

void check_mouse_turrettwo(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turrettwo);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turrettwo, info->turret_two_logo, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turrettwo, info->turret_two_logo, 0);
    }
}

void check_mouse_wall(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretthree);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretthree, info->wall_texture, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretthree, info->wall_texture, 0);
    }
}