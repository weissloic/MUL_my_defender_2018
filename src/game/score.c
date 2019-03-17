/*
** EPITECH PROJECT, 2019
** score.c
** File description:
** score for my_defender
*/

#include "../../include/runner.h"

void print_score(info_t *info)
{
    char *score = my_itoa(info->score_int);
    char dollar[5] = {"$"};
    my_strcat(dollar, score);

    sfText_setString(info->score_text, dollar);
    sfRenderWindow_drawText(info->window, info->score_text, NULL);
}

void setup_score(info_t *info)
{
    info->score_text = sfText_create();
    info->score_pos.x = 67;
    info->score_pos.y = 517;
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->score_text, info->font);
    sfText_setPosition(info->score_text, info->score_pos);
}

void analyse_time(info_t *info)
{
    float time = sfClock_getElapsedTime(info->score).SEC;

    if (time > 1) {
        info->score_int++;
        sfClock_restart(info->score);
    }
}

void move_monster_time(info_t *info, scene_t *scene)
{
    info->seconds = sfClock_getElapsedTime(info->clock).SEC;

    if (info->seconds > 0.01) {
        if (info->new_pos.x == 150 && info->new_pos.y == 40) {
            info->new_pos.y = 40;
            info->new_pos.x += 10;
        }
        else if (info->new_pos.x == 150) {
            info->new_pos.x = 150;
            info->new_pos.y += 2;
        }
        else
            info->new_pos.x += 2;
        sfSprite_setPosition(scene[1].monster, info->new_pos);
        sfClock_restart(info->clock);
    }
}

void pos_inventory(info_t *info, scene_t *scene)
{
            if (info->get_turret == 1)
                create_turret(info, scene);
            if (info->fill_turret == 1)
                create_turrettwo(info, scene);
            if (info->get_turrettwo == 1)
                func2_create_turret(info, scene);
            pos_inventorytwo(info, scene);

}