/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events for my_runner
*/

#include "include/runner.h"

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
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && info->view == 4 && info->switch_scene == 1)
        info->view = 1;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && info->view == 1 && info->switch_scene != 1)
        info->view = 4;
}

void but_detect(info_t *info, scene_t *scene, sfVector2i mouse_pos)
{
    if (info->view == 0) {
        check_mouse_hovering(scene[info->view].button[0], mouse_pos, info);
        check_mouse_hoveringtwo(scene[info->view].button[1], mouse_pos, info);
        check_mouse_hoveringthree(scene[info->view].button[2], mouse_pos, info);
        check_mouse_hoveringfour(scene[info->view].button[3], mouse_pos, info);
    }
}

void print_full(info_t *info, scene_t *scene, sfVector2i mouse_pos, button_t *button)
{
        if (info->view == 1) {
            print_game(info, scene, button, mouse_pos);
            info->tmp = 1;
        }
        else if (info->view == 0)
            print_menu(info, scene, button, mouse_pos);

        if (info->view == 2)
            print_shop_menu(info, scene, button, mouse_pos);
        else if (info->view == 4)
            print_pause_menu(info, scene, button, mouse_pos);
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

void print_gametwo(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (button_buy_turretone(scene[1].button[3], mouse_pos))
                scene[1].button[3].callback(info);
            if (button_buy_turrettwo(scene[1].button[4], mouse_pos))
                scene[1].button[4].callback(info);
            if (button_buy_wall(scene[1].button[5], mouse_pos))
                scene[1].button[5].callback(info);
            if (button_buy_turretfour(scene[1].button[6], mouse_pos))
                scene[1].button[6].callback(info);
}

void print_gamethree(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (info->get_turret == 1)
                positionning_turret(info, mouse_pos);
            if (info->get_turrettwo == 1)
                positionning_turrettwo(info, mouse_pos);
            if (info->get_turretthree == 1)
                positionning_turretthree(info, mouse_pos);
}

void print_game(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (button_is_clickedpause(scene[1].button[0], mouse_pos))
                scene[1].button[0].callback(info);
            if (button_is_clickedshop(scene[1].button[1], mouse_pos))
                scene[1].button[1].callback(info);
            if (put_in_pausegame(scene[1].button[2], mouse_pos))
                scene[1].button[2].callback(info);
            print_gametwo(info, scene, button, mouse_pos);
            print_gamethree(info, scene, button, mouse_pos);

}

void print_menu(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (button_is_clicked(scene[0].button[0], mouse_pos))
                scene[0].button[0].callback(info);
            if (button_is_clickedtwo(scene[0].button[1], mouse_pos))
                scene[0].button[1].callback(info);
            if (button_is_clickedthree(scene[0].button[2], mouse_pos))
                scene[0].button[2].callback(info);
            if (button_is_clickedfour(scene[0].button[3], mouse_pos))
                scene[0].button[3].callback(info);
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
            if (button_buy_wall(scene[2].button[2], mouse_pos))
                scene[2].button[2].callback(info);
            if (button_buy_turretfour(scene[2].button[3], mouse_pos))
                scene[2].button[3].callback(info);
            print_shop_menutwo(info, scene, button, mouse_pos);
}

void print_shop_menutwo(info_t *info, scene_t *scene, button_t *button, sfVector2i mouse_pos)
{
            if (button_backtogame(scene[2].button[4], mouse_pos))
                scene[2].button[4].callback(info);
}

void delete_turretone(info_t *info, sfVector2i mouse_pos)
{
    if (info->counter_turretone == 4)
        info->counter_turretone--;
    else if (info->counter_turretone == 3) {
        info->register_pos.x = mouse_pos.x;
        info->register_pos.y = mouse_pos.y;
        info->fill_turret = 1;
        info->counter_turretone = 2;
    }
    else if (info->counter_turretone == 2) {
        info->register_postwo.x = mouse_pos.x;
        info->register_postwo.y = mouse_pos.y;
        info->fill_turret = 1;
        info->counter_turretone = 1;  
    }
    else if (info->counter_turretone == 1) {
        info->register_posthree.x = mouse_pos.x;
        info->register_posthree.y = mouse_pos.y;
        info->fill_turret = 1;
        info->counter_turretone = 0;
    }
}

void positionning_turret(info_t *info, sfVector2i mouse_pos)
{
    delete_turretone(info, mouse_pos);
    if (info->counter_turretone == 0)
        info->get_turret = 0;
}

void delete_turrettwo(info_t *info, sfVector2i mouse_pos)
{
    if (info->counter_turrettwo == 4)
        info->counter_turrettwo--;
    else if (info->counter_turrettwo == 3) {
        info->register_posonettwo.x = mouse_pos.x;
        info->register_posonettwo.y = mouse_pos.y;
        info->fill_turrettwo = 1;
        info->counter_turrettwo = 2;
    }
    else if (info->counter_turrettwo == 2) {
        info->register_postwottwo.x = mouse_pos.x;
        info->register_postwottwo.y = mouse_pos.y;
        info->fill_turrettwo = 1;
        info->counter_turrettwo = 1;  
    }
    else if (info->counter_turrettwo == 1) {
        info->register_posthreettwo.x = mouse_pos.x;
        info->register_posthreettwo.y = mouse_pos.y;
        info->fill_turrettwo = 1;
        info->counter_turrettwo = 0;
    }
}

void positionning_turrettwo(info_t *info, sfVector2i mouse_pos)
{
    delete_turrettwo(info, mouse_pos);
    if (info->counter_turrettwo == 0)
        info->get_turrettwo = 0;
}

void delete_turrethree(info_t *info, sfVector2i mouse_pos)
{
    if (info->counter_turretthree == 4)
        info->counter_turretthree--;
    else if (info->counter_turretthree == 3) {
        info->register_posonetthree.x = mouse_pos.x;
        info->register_posonetthree.y = mouse_pos.y;
        info->fill_turretthree = 1;
        info->counter_turretthree = 2;
    }
    else if (info->counter_turretthree == 2) {
        info->register_postwotthree.x = mouse_pos.x;
        info->register_postwotthree.y = mouse_pos.y;
        info->fill_turretthree = 1;
        info->counter_turretthree = 1;  
    }
    else if (info->counter_turretthree == 1) {
        info->register_posthreetthree.x = mouse_pos.x;
        info->register_posthreetthree.y = mouse_pos.y;
        info->fill_turretthree = 1;
        info->counter_turretthree = 0;
    }
}

void positionning_turretthree(info_t *info, sfVector2i mouse_pos)
{
    delete_turrethree(info, mouse_pos);
    if (info->counter_turretthree == 0)
        info->get_turretthree = 0;
}


void check_mouse_shopmenu(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_shop);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_shop, info->start_rect);
        sfRectangleShape_setTexture(button.rect_shop, info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_shop, info->start_rect);
        sfRectangleShape_setTexture(button.rect_shop, info->second_button_normal, 0);
    }
}

void check_mouse_nukebutton(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretfour);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretfour, info->nuke_logo, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretfour, info->nuke_logo, 0);
    }
}

void check_mouse_turretone(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretone);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretone, info->turret_one_logo, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretone, info->turret_one_logo, 0);
    }
}

void check_mouse_turrettwo(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turrettwo);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turrettwo, info->turret_two_logo, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turrettwo, info->turret_two_logo, 0);
    }
}

void check_mouse_wall(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretthree);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 200 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 100) {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretthree, info->wall_texture, 0);
    }
    else {
        info->start_rect.left = 75;
        info->start_rect.top = 250;
        info->start_rect.width = 60;
        info->start_rect.height = 60;
        sfRectangleShape_setTexture(button.rect_turretthree, info->wall_texture, 0);
    }
}