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