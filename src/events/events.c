/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "../../include/runner.h"

void init_full_button(info_t *info, scene_t *scene, sfVector2i mouse_pos)
{
    check_mouse_upgrademenu(scene[1].button[0], mouse_pos, info);
    check_mouse_shopmenu(scene[1].button[1], mouse_pos, info);
    check_mouse_nukebutton(scene[2].button[3], mouse_pos, info);
    check_mouse_turretone(scene[2].button[0], mouse_pos, info);
    check_mouse_turrettwo(scene[2].button[1], mouse_pos, info);
    check_mouse_wall(scene[2].button[2], mouse_pos, info);
    check_mouse_nukebutton(scene[1].button[6], mouse_pos, info);
    check_mouse_turretone(scene[1].button[3], mouse_pos, info);
    check_mouse_turrettwo(scene[1].button[4], mouse_pos, info);
    check_mouse_wall(scene[1].button[5], mouse_pos, info);
    check_mouse_pause(scene[1].button[2], mouse_pos, info);
    check_gobacktogame(scene[2].button[4], mouse_pos, info);
    check_mouse_resume(scene[4].button[0], mouse_pos, info);
    check_mouse_backmenu(scene[4].button[1], mouse_pos, info);
    check_mouse_exitgame(scene[4].button[2], mouse_pos, info);
}

void init_pause(info_t *info)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue 
    && info->view == 4 && info->switch_scene == 1)
        info->view = 1;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue 
    && info->view == 1 && info->switch_scene != 1)
        info->view = 4;
}

void but_detect(info_t *info, scene_t *scene, sfVector2i mouse_pos)
{
    if (info->view == 0) {
        check_mouse_hovering(scene[info->view].button[0], mouse_pos, info);
        check_mouse_hoveringtwo(scene[info->view].button[1], mouse_pos, info);
        check_mouse_hoveringthree(scene[info->view].button[2],
        mouse_pos, info);
        check_mouse_hoveringfour(scene[info->view].button[3], mouse_pos, info);
    }
}

void print_full(info_t *info, scene_t *scene, sfVector2i pos, button_t *button)
{
        if (info->view == 1) {
            print_game(info, scene, button, pos);
            info->tmp = 1;
        }
        else if (info->view == 0)
            print_menu(info, scene, button, pos);
        if (info->view == 2)
            print_shop_menu(info, scene, button, pos);
        else if (info->view == 4)
            print_pause_menu(info, scene, button, pos);
}

void analyse_events(info_t *info, scene_t *scene, button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);

    but_detect(info, scene, mouse_pos);

    init_full_button(info, scene, mouse_pos);
    if (info->event.type == sfEvtClosed)
        sfRenderWindow_close(info->window);
    init_pause(info);
    if (info->event.type == sfEvtMouseButtonPressed && info->view != 3) {
        print_full(info, scene, mouse_pos, button);
    }
}