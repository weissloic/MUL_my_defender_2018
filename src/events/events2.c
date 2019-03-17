/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "../../include/runner.h"

void print_gametwo(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
    if (button_buy_turretone(scene[1].button[3], mouse_pos))
        scene[1].button[3].callback(info);
    if (button_buy_turrettwo(scene[1].button[4], mouse_pos))
        scene[1].button[4].callback(info);
    if (button_buy_wall(scene[1].button[5], mouse_pos))
        scene[1].button[5].callback(info);
    if (button_buy_turretfour(scene[1].button[6], mouse_pos))
        scene[1].button[6].callback(info);
}

void print_gamethree(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
    if (info->get_turret == 1)
        positionning_turret(info, mouse_pos);
    if (info->get_turrettwo == 1)
        positionning_turrettwo(info, mouse_pos);
    if (info->get_turretthree == 1)
        positionning_turretthree(info, mouse_pos);
}

void print_game(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
    if (button_is_clickedpause(scene[1].button[0], mouse_pos))
        scene[1].button[0].callback(info);
    if (button_is_clickedshop(scene[1].button[1], mouse_pos))
        scene[1].button[1].callback(info);
    if (put_in_pausegame(scene[1].button[2], mouse_pos))
        scene[1].button[2].callback(info);
    print_gametwo(info, scene, button, mouse_pos);
    print_gamethree(info, scene, button, mouse_pos);

}

void print_menu(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
    if (button_is_clicked(scene[0].button[0], mouse_pos))
        scene[0].button[0].callback(info);
    if (button_is_clickedtwo(scene[0].button[1], mouse_pos))
        scene[0].button[1].callback(info);
    if (button_is_clickedthree(scene[0].button[2], mouse_pos))
        scene[0].button[2].callback(info);
    if (button_is_clickedfour(scene[0].button[3], mouse_pos))
        scene[0].button[3].callback(info);
}

void print_pause_menu(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
    if (button_is_clickedresume(scene[4].button[0], mouse_pos))
        scene[4].button[0].callback(info);
    if (button_is_clickedbackmenu(scene[4].button[1], mouse_pos))
        scene[4].button[1].callback(info);
    if (button_is_clickedsound(scene[4].button[2], mouse_pos))
        scene[4].button[2].callback(info);
}
