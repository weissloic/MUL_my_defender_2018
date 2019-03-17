/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "../../include/runner.h"

void positionning_turrettwo(info_t *info, sfVector2i mouse_pos)
{
    delete_turrettwo(info, mouse_pos);
    if (info->counter_turrettwo == 0)
        info->get_turrettwo = 0;
}

void delete_turrethree(info_t *info, sfVector2i mouse_pos)
{
    if (info->counter_turretthree == 4)
        info->counter_turretthree--;
    else if (info->counter_turretthree == 3) {
        info->register_posonetthree.x = mouse_pos.x;
        info->register_posonetthree.y = mouse_pos.y;
        info->fill_turretthree = 1;
        info->counter_turretthree = 2;
    }
    else if (info->counter_turretthree == 2) {
        info->register_postwotthree.x = mouse_pos.x;
        info->register_postwotthree.y = mouse_pos.y;
        info->fill_turretthree = 1;
        info->counter_turretthree = 1;  
    }
    else if (info->counter_turretthree == 1) {
        info->register_posthreetthree.x = mouse_pos.x;
        info->register_posthreetthree.y = mouse_pos.y;
        info->fill_turretthree = 1;
        info->counter_turretthree = 0;
    }
}

void positionning_turretthree(info_t *info, sfVector2i mouse_pos)
{
    delete_turrethree(info, mouse_pos);
    if (info->counter_turretthree == 0)
        info->get_turretthree = 0;
}


void check_mouse_shopmenu(button_t but, sfVector2i mouse_pos, info_t *i)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(but.rect_shop);

    if (mouse_pos.x >= button_pos.x && mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y && mouse_pos.y <= button_pos.y + 80) {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 70;
        i->start_rect.height = 80;
        sfRectangleShape_setTextureRect(but.rect_shop, i->start_rect);
        sfRectangleShape_setTexture(but.rect_shop, i->second_button_hover, 0);
    }
    else {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 70;
        i->start_rect.height = 80;
        sfRectangleShape_setTextureRect(but.rect_shop, i->start_rect);
        sfRectangleShape_setTexture(but.rect_shop, i->second_button_normal, 0);
    }
}

void check_mouse_nukebutton(button_t but, sfVector2i mouse_pos, info_t *i)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(but.rect_turretfour);

    if (mouse_pos.x >= button_pos.x && mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y && mouse_pos.y <= button_pos.y + 100) {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 60;
        i->start_rect.height = 60;
        sfRectangleShape_setTexture(but.rect_turretfour, i->nuke_logo, 0);
    }
    else {
        i->start_rect.left = 75;
        i->start_rect.top = 250;
        i->start_rect.width = 60;
        i->start_rect.height = 60;
        sfRectangleShape_setTexture(but.rect_turretfour, i->nuke_logo, 0);
    }
}