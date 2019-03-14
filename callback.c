/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/runner.h"

void exit_window(info_t *info)
{
    sfRenderWindow_close(info->window);
}

void goto_shopmenu(info_t *info)
{
    info->view = 2;
}

void goto_pausemenu(info_t *info)
{
    info->view = 4;
    //info->get_turret = 1;
}

void goto_game(info_t *info)
{
    info->view = 1;
}

void play(info_t *info)
{
    info->view++;
    printf("%d\n", info->view);
}

void coupe_decale(info_t *info)
{
    info->menu_turret = 1;
    printf("%d\n", info->menu_turret);
}

void exit_turret_menu(info_t *info)
{
    info->menu_turret = 0;
}