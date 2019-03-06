/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "include/runner.h"

void analyse_events(info_t *info, scene_t *scene, button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f mouse_pos_float = {mouse_pos.x, mouse_pos.y};

    if (info->view != 3) {
        for (int i = 0; scene[info->view].button[i].rect != NULL; i++)
    	   check_mouse_hovering(scene[info->view].button[i], mouse_pos, info);
    }
    if (info->event.type == sfEvtClosed)
        sfRenderWindow_close(info->window);
    if (info->event.type == sfEvtMouseButtonPressed && info->view != 3) {
        if (info->view == 1)
            sfSprite_setPosition(info->test_image, mouse_pos_float);
        for (int i = 0; scene[info->view].button[i].rect != NULL; i++)
            if (button_is_clicked(scene[info->view].button[i], mouse_pos)) {
                scene[info->view].button[i].callback(info);
        }
    }
}

void check_mouse_hovering(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100)
    	sfRectangleShape_setTexture(button.rect, info->button_hover, 0);
	else
    	sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
}