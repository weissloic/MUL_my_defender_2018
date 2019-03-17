/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** music
*/

#include "../../include/runner.h"

void create_music(info_t *info)
{
    info->main_music = sfMusic_createFromFile("ressources/gamemusic.ogg");
    info->yes_money = sfMusic_createFromFile("ressources/argent.ogg");
    info->no_money = sfMusic_createFromFile("ressources/buzzer.ogg");
    info->nuclear = sfMusic_createFromFile("ressources/nucleaire.ogg");
}

void destroy_music(info_t *info)
{
    sfMusic_destroy(info->main_music);
    sfMusic_destroy(info->yes_money);
    sfMusic_destroy(info->no_money);
    sfMusic_destroy(info->nuclear);
}