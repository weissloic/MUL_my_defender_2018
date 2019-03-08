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

    if (info->view != 3 && info->view != 1) {
    	   check_mouse_hovering(scene[info->view].button[0], mouse_pos, info);
           check_mouse_hoveringtwo(scene[info->view].button[1], mouse_pos, info);
           check_mouse_hoveringthree(scene[info->view].button[2], mouse_pos, info);
   }
   check_mouse_pausemenu(scene[1].button[0], mouse_pos, info);

    if (info->event.type == sfEvtClosed)
        sfRenderWindow_close(info->window);

    if (info->event.type == sfEvtMouseButtonPressed && info->view != 3) {
        if (info->view == 1)
            sfSprite_setPosition(info->test_image, mouse_pos_float);

        //for (int i = 0; scene[info->view].button[i].rect != NULL; i++)
        if (info->view == 0) {
            if (button_is_clicked(scene[0].button[0], mouse_pos))
                scene[0].button[0].callback(info);
        //}
        //for (int i = 0; scene[info->view].button[i].rect_two != NULL; i++)
        if (button_is_clickedtwo(scene[0].button[1], mouse_pos)) {
            scene[0].button[1].callback(info);
        }
        if (button_is_clickedthree(scene[0].button[2], mouse_pos)) {
            scene[0].button[2].callback(info);
        }
    }
    if (button_is_clickedtower(scene[1].button[1], mouse_pos))
        scene[1].button[1].callback(info, button[1]);
    if (button_is_clickedpause(scene[1].button[0], mouse_pos))
        scene[1].button[0].callback(info);
    }
}

void check_mouse_hovering(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {

        info->start_rect.left = 0;
        info->start_rect.top = 72;
        info->start_rect.width = 200;
        info->start_rect.height = 70;
        sfRectangleShape_setTextureRect(button.rect, info->start_rect);
        //sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
	else {
        info->start_rect.left = 0;
        info->start_rect.top = 0;
        info->start_rect.width = 200;
        info->start_rect.height = 70;
        sfRectangleShape_setTextureRect(button.rect, info->start_rect);
        sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    	//sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
}

void check_mouse_hoveringtwo(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_two);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {

        info->start_rect.left = 0;
        info->start_rect.top = 72;
        info->start_rect.width = 200;
        info->start_rect.height = 70;
        sfRectangleShape_setTextureRect(button.rect_two, info->start_rect);
        //sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
    else {
        info->start_rect.left = 0;
        info->start_rect.top = 0;
        info->start_rect.width = 200;
        info->start_rect.height = 70;
        sfRectangleShape_setTextureRect(button.rect_two, info->start_rect);
        sfRectangleShape_setTexture(button.rect_two, info->test, 0);
        //sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
}

void check_mouse_hoveringthree(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_three);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {

        info->start_rect.left = 0;
        info->start_rect.top = 72;
        info->start_rect.width = 200;
        info->start_rect.height = 70;
        sfRectangleShape_setTextureRect(button.rect_three, info->start_rect);
        //sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
    else {
        info->start_rect.left = 0;
        info->start_rect.top = 0;
        info->start_rect.width = 200;
        info->start_rect.height = 70;
        sfRectangleShape_setTextureRect(button.rect_three, info->start_rect);
        sfRectangleShape_setTexture(button.rect_three, info->test, 0);
        //sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
}

void check_mouse_pausemenu(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pause);

    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {

        info->start_rect.left = 0;
        info->start_rect.top = 72;
        info->start_rect.width = 200;
        info->start_rect.height = 70;
        sfRectangleShape_setTextureRect(button.rect_pause, info->start_rect);
        //sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
    else {
        info->start_rect.left = 0;
        info->start_rect.top = 0;
        info->start_rect.width = 200;
        info->start_rect.height = 70;
        sfRectangleShape_setTextureRect(button.rect_pause, info->start_rect);
        sfRectangleShape_setTexture(button.rect_pause, info->test, 0);
        //sfRectangleShape_setTexture(button.rect, info->button_normal, 0);
    }
}