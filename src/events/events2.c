/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "../../include/runner.h"

void print_gametwo(info_t *i, scene_t *scene, button_t *button, sfVector2i pos)
{
    if (button_buy_turretone(scene[1].button[3], pos))
        scene[1].button[3].callback(i);
    if (button_buy_turrettwo(scene[1].button[4], pos))
        scene[1].button[4].callback(i);
    if (button_buy_wall(scene[1].button[5], pos))
        scene[1].button[5].callback(i);
    if (button_buy_turretfour(scene[1].button[6], pos))
        scene[1].button[6].callback(i);
}

void print_gamethree(info_t *i, scene_t *scene, button_t *but, sfVector2i pos)
{
    if (i->get_turret == 1)
        positionning_turret(i, pos);
    if (i->get_turrettwo == 1)
        positionning_turrettwo(i, pos);
    if (i->get_turretthree == 1)
        positionning_turretthree(i, pos);
}

void print_game(info_t *info, scene_t *scene, button_t *button, sfVector2i pos)
{
    if (button_is_clickedpause(scene[1].button[0], pos))
        scene[1].button[0].callback(info);
    if (button_is_clickedshop(scene[1].button[1], pos))
        scene[1].button[1].callback(info);
    if (put_in_pausegame(scene[1].button[2], pos))
        scene[1].button[2].callback(info);
    print_gametwo(info, scene, button, pos);
    print_gamethree(info, scene, button, pos);
}

void print_menu(info_t *info, scene_t *scene, button_t *button, sfVector2i pos)
{
    if (button_is_clicked(scene[0].button[0], pos))
        scene[0].button[0].callback(info);
    if (button_is_clickedtwo(scene[0].button[1], pos))
        scene[0].button[1].callback(info);
    if (button_is_clickedthree(scene[0].button[2], pos))
        scene[0].button[2].callback(info);
    if (button_is_clickedfour(scene[0].button[3], pos))
        scene[0].button[3].callback(info);
}

void print_pause_menu(info_t *i, scene_t *sc, button_t *button, sfVector2i pos)
{
    if (button_is_clickedresume(sc[4].button[0], pos))
        sc[4].button[0].callback(i);
    if (button_is_clickedbackmenu(sc[4].button[1], pos))
        sc[4].button[1].callback(i);
    if (button_is_clickedsound(sc[4].button[2], pos))
        sc[4].button[2].callback(i);
}
