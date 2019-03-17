/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "../../include/runner.h"

void check_mouse_turretone(button_t but, sfVector2i mouse_pos, info_t *i)
{
    sfVector2f but_pos = sfRectangleShape_getPosition(but.rect_turretone);
    if (mouse_pos.x >= but_pos.x &&
        mouse_pos.x <= but_pos.x + 200 &&
        mouse_pos.y >= but_pos.y &&
        mouse_pos.y <= but_pos.y + 100) {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 60;
        i->start_rect.height = 60;
        sfRectangleShape_setTexture(but.rect_turretone, i->turret_one_logo, 0);
    }
    else {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 60;
        i->start_rect.height = 60;
        sfRectangleShape_setTexture(but.rect_turretone, i->turret_one_logo, 0);
    }
}

void check_mouse_turrettwo(button_t but, sfVector2i mouse_pos, info_t *i)
{
    sfVector2f but_pos = sfRectangleShape_getPosition(but.rect_turrettwo);
    if (mouse_pos.x >= but_pos.x &&
        mouse_pos.x <= but_pos.x + 200 &&
        mouse_pos.y >= but_pos.y &&
        mouse_pos.y <= but_pos.y + 100) {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 60;
        i->start_rect.height = 60;
        sfRectangleShape_setTexture(but.rect_turrettwo, i->turret_two_logo, 0);
    }
    else {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 60;
        i->start_rect.height = 60;
        sfRectangleShape_setTexture(but.rect_turrettwo, i->turret_two_logo, 0);
    }
}

void check_mouse_wall(button_t but, sfVector2i mouse_pos, info_t *i)
{
    sfVector2f but_pos = sfRectangleShape_getPosition(but.rect_turretthree);

    if (mouse_pos.x >= but_pos.x &&
        mouse_pos.x <= but_pos.x + 200 &&
        mouse_pos.y >= but_pos.y && mouse_pos.y <= but_pos.y + 100) {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 60;
        i->start_rect.height = 60;
        sfRectangleShape_setTexture(but.rect_turretthree, i->wall_texture, 0);
    }
    else {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 60;
        i->start_rect.height = 60;
        sfRectangleShape_setTexture(but.rect_turretthree, i->wall_texture, 0);
    }
}