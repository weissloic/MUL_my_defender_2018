/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** music
*/

#include "include/runner.h"

void create_music(info_t *info)
{
    info->main_music = sfMusic_createFromFile("ressources/gamemusic.ogg");
}

void destroy_music(info_t *info)
{
    sfMusic_destroy(info->main_music);
}