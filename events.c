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
            print_game(info, scene, button, mouse_pos);
        }
        else if (info->view == 0) {
            print_menu(info, scene, button, mouse_pos);
        }
        else if (info->view == 2) {
            print_shop_menu(info, scene, button, mouse_pos);
        }
        else if (info->view == 4) {
            print_pause_menu(info, scene, button, mouse_pos);
        }
    }
}

void print_game(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (button_is_clickedpause(scene[1].button[0], mouse_pos))
                scene[1].button[0].callback(info);
            if (button_is_clickedshop(scene[1].button[1], mouse_pos))
                scene[1].button[1].callback(info);
            if (put_in_pausegame(scene[1].button[2], mouse_pos))
                scene[1].button[2].callback(info);
            if (info->get_turret == 1)
                positionning_turret(info, mouse_pos);
}

void print_menu(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (button_is_clicked(scene[0].button[0], mouse_pos))
                scene[0].button[0].callback(info);
            if (button_is_clickedtwo(scene[0].button[1], mouse_pos))
                scene[0].button[1].callback(info);
            if (button_is_clickedthree(scene[0].button[2], mouse_pos))
                scene[0].button[2].callback(info);
}

void print_pause_menu(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (button_is_clickedresume(scene[4].button[0], mouse_pos))
                scene[4].button[0].callback(info);
            if (button_is_clickedbackmenu(scene[4].button[1], mouse_pos))
                scene[4].button[1].callback(info);
            if (button_is_clickedsound(scene[4].button[2], mouse_pos))
                scene[4].button[2].callback(info);
}

void print_shop_menu(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (button_buy_turretone(scene[2].button[0], mouse_pos))
                scene[2].button[0].callback(info);
            if (button_buy_turrettwo(scene[2].button[1], mouse_pos))
                scene[2].button[1].callback(info);
            if (button_buy_turretthree(scene[2].button[2], mouse_pos))
                scene[2].button[2].callback(info);
            if (button_buy_turretfour(scene[2].button[3], mouse_pos))
                scene[2].button[3].callback(info);
}

void positionning_turret(info_t *info, sfVector2i mouse_pos)
{
            if (info->counter_turretone == 4)
                info->counter_turretone--;
            else if (info->counter_turretone == 3) {
                info->register_pos.x = mouse_pos.x;
                info->register_pos.y = mouse_pos.y;
                info->fill_turret = 1;
                info->counter_turretone--;
            }
            else if (info->counter_turretone == 2) {
                info->register_postwo.x = mouse_pos.x;
                info->register_postwo.y = mouse_pos.y;
                info->fill_turret = 1;
                info->counter_turretone--;  
            }
            else if (info->counter_turretone == 1) {
                info->register_posthree.x = mouse_pos.x;
                info->register_posthree.y = mouse_pos.y;
                info->fill_turret = 1;
                info->counter_turretone--;  
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