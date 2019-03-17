/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void exit_window(info_t *info)
{
    sfRenderWindow_close(info->window);
}

void goto_shopmenu(info_t *info)
{
    info->view = 2;
}

void price_turretone(info_t *info)
{
    if (info->score_int > 20) {
        info->score_int -= 20;
        sfMusic_play(info->yes_money);
    }
    else
        sfMusic_play(info->no_money);
}

void price_turrettwo(info_t *info)
{
    if (info->score_int > 50) {
        info->score_int -= 50;
        sfMusic_play(info->yes_money);
    }
    else
        sfMusic_play(info->no_money);
}

void price_turretthree(info_t *info)
{
    if (info->score_int > 75) {
        info->score_int -= 75;
        sfMusic_play(info->yes_money);
    }
    else
        sfMusic_play(info->no_money);
}

void nuclear_func(info_t *info)
{
    sfMusic_play(info->nuclear);
}

void price_nuclear(info_t *info)
{
    if (info->score_int > 500) {
        info->score_int -= 500;
        sfMusic_play(info->yes_money);
    }
    else
        sfMusic_play(info->no_money);
}

void goto_pausemenu(info_t *info)
{
    info->view = 4;
}

void goto_menu(info_t *info)
{
    info->view = 0;
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
    //printf("%d\n", info->menu_turret);
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