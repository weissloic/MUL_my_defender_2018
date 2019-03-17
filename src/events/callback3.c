/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

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
}