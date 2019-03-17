/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void init_value(info_t *info)
{
    info->view = 0;
    info->initial_parallax.x = 800;
    info->castle_position.x = 635;
    info->castle_position.y = 410;
    info->new_pos.x = 0;
    info->new_pos.y = 35;
    info->counter_turretone = 4;
    info->counter_turretthree = 4;
    info->pos_turretone.x = 400;
    info->pos_turretone.y = 300;
    info->pos_turrettwo.x = 400;
    info->pos_turrettwo.y = 200;
    info->pos_menu.x = 400;
    info->pos_menu.y = 300;
    info->register_pos.x = 900;
    info->register_pos.y = 900;
    info->register_postwo.x = 900;
    info->register_postwo.y = 900;
    info->register_posthree.x = 900;
    info->register_posthree.y = 900;
}

void init_valuetwo(info_t *info)
{
    info->register_posonettwo.x = 900;
    info->register_posonettwo.y = 900;
    info->register_postwottwo.x = 900;
    info->register_postwottwo.y = 900;
    info->register_posthreettwo.x = 900;
    info->register_posthreettwo.y = 900;
    info->register_posonetthree.x = 900;
    info->register_posonetthree.y = 900;
    info->register_postwotthree.x = 900;
    info->register_postwotthree.y = 900;
    info->register_posthreetthree.x = 900;
    info->register_posthreetthree.y = 900;
    info->menu_turret = 0;
    info->zombie_rect.left = 0;
    info->zombie_rect.top = 0;
    info->zombie_rect.width = 60;
    info->zombie_rect.height = 70;
    info->shopmenu_pos.x = 0;
    info->shopmenu_pos.y = 400;
    info->counter_turrettwo = 4;
}

void init_valuethree(info_t *info)
{
    init_value(info);
    init_valuetwo(info);
    
    info->money_pos.x = 155;
    info->money_pos.y = 510;
    info->shophouse_pos.x = 625;
    info->shophouse_pos.y = 0;
    info->sign_price_pos1.x = 80;
    info->sign_price_pos1.y = 370;
    info->sign_price_pos2.x = 230;
    info->sign_price_pos2.y = 370;
    info->sign_price_pos3.x = 380;
    info->sign_price_pos3.y = 370;
    info->sign_price_pos4.x = 530;
    info->sign_price_pos4.y = 370;
    info->tmp = 0;
    info->seconds = sfClock_getElapsedTime(info->clock).SEC;
}

void my_view_one(info_t *info, scene_t *scene)
{
    info->switch_scene = 0;
    analyse_time(info);
            move_monster_time(info, scene);
            sfRenderWindow_drawSprite(info->window, scene[1].background, NULL);
            sfRenderWindow_drawSprite(info->window, scene[1].monster, NULL);
            sfRenderWindow_drawSprite(info->window, info->shopmenu, NULL);
            sfRenderWindow_drawSprite(info->window, info->dollar, NULL);
            sfRenderWindow_drawSprite(info->window, info->castle_sprite, NULL);
            if (info->tmp == 1)
                sfRenderWindow_drawSprite(info->window, info->explosion, NULL);
            my_inventory(info, scene);
            pos_inventory(info, scene);
            sfRectangleShape_setPosition(scene[1].button[0].rect_pause, info->pos_menu);
            sfRenderWindow_drawRectangleShape(info->window, scene[1].button[0].rect_pause, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[1].button[1].rect_shop, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[1].button[2].rect_putinpause, NULL);
            print_score(info);
}

void my_view_null(info_t *info, scene_t *scene)
{
            parallax_main_menu(info, scene);
            sfRenderWindow_drawSprite(info->window, scene[0].background, NULL);
            sfRenderWindow_drawSprite(info->window, scene[0].background_mainmenu, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[0].button[0].rect, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[0].button[1].rect_two, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[0].button[2].rect_three, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[0].button[3].rect_four, NULL);
}