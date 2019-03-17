/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void check_mouse_upgrademenu(button_t button, sfVector2i mouse_pos,
info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pause);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 80 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {
        muse_two(button, mouse_pos, info);
    }
    else {
        info->start_rect.left = 520;
        info->start_rect.top = 165;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTextureRect(button.rect_pause, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pause,
        info->second_button_normal, 0);
    }
}

int button_is_clickedpause(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pause);

    if (click_position.x >= button_pos.x + 80 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 80)
        return (1);
    else
        return (0);
}

void func3_create_turret(info_t *info, scene_t *scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f mouse_pos_float = {mouse_pos.x, mouse_pos.y};

    sfSprite_setPosition(scene[1].turretthree, mouse_pos_float);
    sfRenderWindow_drawSprite(info->window, scene[1].turretthree, NULL);
}

void func3_create_turrettwo(info_t *info, scene_t *scene)
{
    sfSprite_setPosition(scene[1].turretthree, info->register_posonetthree);
    sfRenderWindow_drawSprite(info->window, scene[1].turretthree, NULL);
    sfSprite_setPosition(scene[1].turretthree, info->register_postwotthree);
    sfRenderWindow_drawSprite(info->window, scene[1].turretthree, NULL);
    sfSprite_setPosition(scene[1].turretthree, info->register_posthreetthree);
    sfRenderWindow_drawSprite(info->window, scene[1].turretthree, NULL);
}