/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "../../include/runner.h"

void print_shop_menu(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
    if (button_buy_turretone(scene[2].button[0], mouse_pos))
        scene[2].button[0].callback(info);
    if (button_buy_turrettwo(scene[2].button[1], mouse_pos))
        scene[2].button[1].callback(info);
    if (button_buy_wall(scene[2].button[2], mouse_pos))
        scene[2].button[2].callback(info);
    if (button_buy_turretfour(scene[2].button[3], mouse_pos))
        scene[2].button[3].callback(info);
    print_shop_menutwo(info, scene, button, mouse_pos);
}

void print_shop_menutwo(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
    if (button_backtogame(scene[2].button[4], mouse_pos))
        scene[2].button[4].callback(info);
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