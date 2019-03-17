/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void coupe_decale(info_t *info)
{
    info->menu_turret = 1;
}

void exit_turret_menu(info_t *info)
{
    info->menu_turret = 0;
}


void fill_map_t_one(info_t *info)
{
    info->fill_turret = 1;
    info->get_turret = 1;
    info->select_or_not = 1;
}

void fill_map_t_two(info_t *info)
{
    info->fill_turrettwo = 1;
    info->get_turrettwo = 1;
}

void fill_map_t_three(info_t *info)
{
    info->fill_turretthree = 1;
    info->get_turretthree = 1;
}