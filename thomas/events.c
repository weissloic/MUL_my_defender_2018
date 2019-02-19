/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "include/runner.h"

void analyse_events(info_t *info, scene_t *scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    if (info->event.type == sfEvtMouseButtonPressed) {
        for (int i = 0; scene[0].button[i].rect != NULL; i++)
            if (button_is_clicked(scene[0].button[i], mouse_pos)) {
                scene[0].button[i].callback(info);
        }
    }
}