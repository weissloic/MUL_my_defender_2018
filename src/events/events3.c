/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "../../include/runner.h"

void print_shop_menu(info_t *i, scene_t *sc, button_t *button, sfVector2i pos)
{
    if (button_buy_turretone(sc[2].button[0], pos))
        sc[2].button[0].callback(i);
    if (button_buy_turrettwo(sc[2].button[1], pos))
        sc[2].button[1].callback(i);
    if (button_buy_wall(sc[2].button[2], pos))
        sc[2].button[2].callback(i);
    if (button_buy_turretfour(sc[2].button[3], pos))
        sc[2].button[3].callback(i);
    print_shop_menutwo(i, sc, button, pos);
}

void print_shop_menutwo(info_t *i, scene_t *sc, button_t *but, sfVector2i pos)
{
    if (button_backtogame(sc[2].button[4], pos))
        sc[2].button[4].callback(i);
}

void delete_turretone(info_t *info, sfVector2i mouse_pos)
{
    if (info->counter_turretone == 4)
        info->counter_turretone--;
    else if (info->counter_turretone == 3) {
        info->register_pos.x = mouse_pos.x;
        info->register_pos.y = mouse_pos.y;
        info->fill_turret = 1;
        info->counter_turretone = 2;
    }
    else if (info->counter_turretone == 2) {
        info->register_postwo.x = mouse_pos.x;
        info->register_postwo.y = mouse_pos.y;
        info->fill_turret = 1;
        info->counter_turretone = 1;  
    }
    else if (info->counter_turretone == 1) {
        info->register_posthree.x = mouse_pos.x;
        info->register_posthree.y = mouse_pos.y;
        info->fill_turret = 1;
        info->counter_turretone = 0;
    }
}

void positionning_turret(info_t *info, sfVector2i mouse_pos)
{
    delete_turretone(info, mouse_pos);
    if (info->counter_turretone == 0)
        info->get_turret = 0;
}

void delete_turrettwo(info_t *info, sfVector2i mouse_pos)
{
    if (info->counter_turrettwo == 4)
        info->counter_turrettwo--;
    else if (info->counter_turrettwo == 3) {
        info->register_posonettwo.x = mouse_pos.x;
        info->register_posonettwo.y = mouse_pos.y;
        info->fill_turrettwo = 1;
        info->counter_turrettwo = 2;
    }
    else if (info->counter_turrettwo == 2) {
        info->register_postwottwo.x = mouse_pos.x;
        info->register_postwottwo.y = mouse_pos.y;
        info->fill_turrettwo = 1;
        info->counter_turrettwo = 1;  
    }
    else if (info->counter_turrettwo == 1) {
        info->register_posthreettwo.x = mouse_pos.x;
        info->register_posthreettwo.y = mouse_pos.y;
        info->fill_turrettwo = 1;
        info->counter_turrettwo = 0;
    }
}