/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** parallax
*/

#include "../../include/runner.h"

void parallax_main_menu(info_t *info, scene_t *scene)
{
    sfVector2f back = sfSprite_getPosition(scene[0].background);
    sfVector2f back2 = sfSprite_getPosition(scene[0].background_mainmenu);

    back.x = back.x - 2;
    back2.x = back2.x - 2;
    sfSprite_setPosition(scene[0].background, back);
    sfSprite_setPosition(scene[0].background_mainmenu, back2);
    if (back.x <= -800)
        sfSprite_setPosition(scene[0].background, info->initial_parallax);
    if (back2.x <= -800)
        sfSprite_setPosition(scene[0].background_mainmenu, info->initial_parallax);
}
