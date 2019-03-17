/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void pos_inventorytwo(info_t *info, scene_t *scene)
{
    if (info->fill_turrettwo == 1)
        func2_create_turrettwo(info, scene);
    if (info->get_turretthree == 1)
        func3_create_turret(info, scene);
    if (info->fill_turretthree == 1)
        func3_create_turrettwo(info, scene);
}

void muse_two(button_t button, sfVector2i mouse_pos,
info_t *info)
{
        info->start_rect.left = 520;
        info->start_rect.top = 165;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTextureRect(button.rect_pause,
        info->start_rect);
        sfRectangleShape_setTexture(button.rect_pause,
        info->second_button_hover, 0);
}

void my_view_two(info_t *info, scene_t *scene)
{
    sfMusic_play(info->main_music);
    sfRenderWindow_drawSprite(info->window, scene[2].background, NULL);
    sfRenderWindow_drawRectangleShape(info->window,
    scene[2].button[0].rect_turretone, NULL);
    sfRenderWindow_drawRectangleShape(info->window,
    scene[2].button[1].rect_turrettwo, NULL);
    sfRenderWindow_drawRectangleShape(info->window,
    scene[2].button[2].rect_turretthree, NULL);
    sfRenderWindow_drawRectangleShape(info->window,
    scene[2].button[3].rect_turretfour, NULL);
    sfRenderWindow_drawRectangleShape(info->window,
    scene[2].button[4].rect_gobackgame, NULL);
    draw_two(info, scene);
    print_score(info);
}