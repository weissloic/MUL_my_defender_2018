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

    if (info->view == 0) {
    	   check_mouse_hovering(scene[info->view].button[0], mouse_pos, info);
           check_mouse_hoveringtwo(scene[info->view].button[1], mouse_pos, info);
           check_mouse_hoveringthree(scene[info->view].button[2], mouse_pos, info);
   }
   check_mouse_upgrademenu(scene[1].button[0], mouse_pos, info);
   check_mouse_shopmenu(scene[1].button[1], mouse_pos, info);

    if (info->event.type == sfEvtClosed)
        sfRenderWindow_close(info->window);

    if (info->event.type == sfEvtMouseButtonPressed && info->view != 3) {
        if (info->view == 1) {
            if (button_is_clickedpause(scene[1].button[0], mouse_pos))
                scene[1].button[0].callback(info);
            if (button_is_clickedshop(scene[1].button[1], mouse_pos))
                scene[1].button[1].callback(info);
            if (put_in_pausegame(scene[1].button[2], mouse_pos))
                scene[1].button[2].callback(info);
        }
        else if (info->view == 0) {
            if (button_is_clicked(scene[0].button[0], mouse_pos))
                scene[0].button[0].callback(info);
            if (button_is_clickedtwo(scene[0].button[1], mouse_pos))
                scene[0].button[1].callback(info);
            if (button_is_clickedthree(scene[0].button[2], mouse_pos))
                scene[0].button[2].callback(info);
        }
        else if (info->view == 2) {
            if (button_buy_turretone(scene[2].button[0], mouse_pos))
                scene[2].button[0].callback(info);
            if (button_buy_turrettwo(scene[2].button[1], mouse_pos))
                scene[2].button[1].callback(info);
            if (button_buy_turretthree(scene[2].button[2], mouse_pos))
                scene[2].button[2].callback(info);
            if (button_buy_turretfour(scene[2].button[3], mouse_pos))
                scene[2].button[3].callback(info);
        }
        else if (info->view == 4) {
            if (button_is_clickedresume(scene[4].button[0], mouse_pos))
                scene[4].button[0].callback(info);
            if (button_is_clickedbackmenu(scene[4].button[1], mouse_pos))
                scene[4].button[1].callback(info);
            if (button_is_clickedsound(scene[4].button[2], mouse_pos))
                scene[4].button[2].callback(info);
        }
    }
}

void check_mouse_hovering(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        sfRectangleShape_setTexture(button.rect, info->button_hover, 0);
    }
	else {
        info->start_rect.left = 0;
        info->start_rect.top = 0;
        info->start_rect.width = 121;
        info->start_rect.height = 55;
        sfRectangleShape_setTextureRect(button.rect, info->start_rect);
        sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
}

void check_mouse_hoveringtwo(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_two);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        sfRectangleShape_setTexture(button.rect_two, info->button_hover, 0);
    }
    else {
        info->start_rect.left = 700;
        info->start_rect.top = 335;
        info->start_rect.width = 121;
        info->start_rect.height = 55;
        sfRectangleShape_setTextureRect(button.rect_two, info->start_rect);
        sfRectangleShape_setTexture(button.rect_two, info->button_normal, 0);
    }
}

void check_mouse_hoveringthree(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_three);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {

        sfRectangleShape_setTexture(button.rect_three, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 300;
        info->start_rect.top = 140;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_three, info->start_rect);
        sfRectangleShape_setTexture(button.rect_three, info->second_button_normal, 0);
    }
}

void check_mouse_upgrademenu(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pause);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {

        info->start_rect.left = 520;
        info->start_rect.top = 165;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTextureRect(button.rect_pause, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pause, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 520;
        info->start_rect.top = 165;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTextureRect(button.rect_pause, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pause, info->second_button_normal, 0);
    }
}
    
void check_mouse_shopmenu(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_shop);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {

        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTextureRect(button.rect_shop, info->start_rect);
        sfRectangleShape_setTexture(button.rect_shop, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTextureRect(button.rect_shop, info->start_rect);
        sfRectangleShape_setTexture(button.rect_shop, info->second_button_normal, 0);
    }
}