/*
** EPITECH PROJECT, 2019
** score.c
** File description:
** score for my_defender
*/

#include "include/runner.h"

void print_score(info_t *info)
{
    char *score = my_itoa(info->score_int);

    sfText_setString(info->score_text, score);
    sfRenderWindow_drawText(info->window, info->score_text, NULL);
}

void setup_score(info_t *info)
{
    info->score_text = sfText_create();
    info->score_pos.x = 10;
    info->score_pos.y = 0;
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->score_text, info->font);
    sfText_setPosition(info->score_text, info->score_pos);
}
