/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void my_inventory(info_t *info, scene_t *scene)
{
    if (info->menu_turret == 1) {
        scene[1].button[0].callback = &exit_turret_menu;
        info->pos_menu.x = 700;
        info->pos_menu.y = 520;
        sfRenderWindow_drawRectangleShape(info->window, scene[1].button[3].rect_turretone, NULL);
        sfRenderWindow_drawRectangleShape(info->window, scene[1].button[4].rect_turrettwo, NULL);
        sfRenderWindow_drawRectangleShape(info->window, scene[1].button[5].rect_turretthree, NULL);
        sfRenderWindow_drawRectangleShape(info->window, scene[1].button[6].rect_turretfour, NULL);
    }
    else {
        scene[1].button[0].callback = &coupe_decale;
        info->pos_menu.x = 700;
        info->pos_menu.y = 200;
    }
}

void create_turret(info_t *info, scene_t *scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f mouse_pos_float = {mouse_pos.x, mouse_pos.y};

    sfSprite_setPosition(scene[1].turretone, mouse_pos_float);
    sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
}

void create_turrettwo(info_t *info, scene_t *scene)
{
    sfSprite_setPosition(scene[1].turretone, info->register_pos);
    sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
    sfSprite_setPosition(scene[1].turretone, info->register_postwo);
    sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
    sfSprite_setPosition(scene[1].turretone, info->register_posthree);
    sfRenderWindow_drawSprite(info->window, scene[1].turretone, NULL);
}

void func2_create_turret(info_t *info, scene_t *scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f mouse_pos_float = {mouse_pos.x, mouse_pos.y};

    sfSprite_setPosition(scene[1].turrettwo, mouse_pos_float);
    sfRenderWindow_drawSprite(info->window, scene[1].turrettwo, NULL);
}

void func2_create_turrettwo(info_t *info, scene_t *scene)
{
    sfSprite_setPosition(scene[1].turrettwo, info->register_posonettwo);
    sfRenderWindow_drawSprite(info->window, scene[1].turrettwo, NULL);
    sfSprite_setPosition(scene[1].turrettwo, info->register_postwottwo);
    sfRenderWindow_drawSprite(info->window, scene[1].turrettwo, NULL);
    sfSprite_setPosition(scene[1].turrettwo, info->register_posthreettwo);
    sfRenderWindow_drawSprite(info->window, scene[1].turrettwo, NULL);
}