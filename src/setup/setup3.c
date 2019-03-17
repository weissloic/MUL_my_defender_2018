/*
** EPITECH PROJECT, 2019
** setup.c
** File description:
** setup sprites and textures for defender
*/

#include "../../include/runner.h"

void setup_scene_0_buttons(scene_t *scene, info_t *info)
{
    sfVector2f size = {200, 100};
    sfVector2f pos2 = {425, 200};
    sfVector2f pos3 = {735, -30};
    sfVector2f pos = {175, 200};
    sfVector2f pos4 = {300, 315};
    sfVector2f size2 = {90, 90};

    init_button(&scene[0].button[0], pos, size, info);
    scene[0].button[0].callback = &play;
    init_buttontwo(&scene[0].button[1], pos2, size, info);
    scene[0].button[1].callback = &exit_window;
    init_buttonthree(&scene[0].button[2], pos3, size2, info);
    scene[0].button[2].callback = &exit_window;
    init_buttonfour(&scene[0].button[3], pos4, size, info);
    scene[0].button[3].callback = &exit_window;
}

void setup_scene_1_buttons(scene_t *scene, info_t *info)
{
    sfVector2f pos_shop = {620, 5};
    sfVector2f pos_pause = {700, 0};
    sfVector2f inv_pos = {900, 300};
    sfVector2f size2 = {90, 90};
    sfVector2f size_turret = {50, 50};
    sfVector2f pos_buyturretoen = {700, 90};
    sfVector2f pos_buyturrettwo = {700, 180};
    sfVector2f pos_buyturretthree = {700, 270};
    sfVector2f pos_buyturretfour = {700, 360};

    init_buttonupgrade(&scene[1].button[0], inv_pos, size2, info);
    scene[1].button[0].callback = &coupe_decale;
    init_buttonshop(&scene[1].button[1], pos_shop, size2, info);
    scene[1].button[1].callback = &goto_shopmenu;
    init_buttonptinpause(&scene[1].button[2], pos_pause, size2, info);
    scene[1].button[2].callback = &goto_pausemenu;
    init_buttonturretone(&scene[1].button[3], pos_buyturretoen, size_turret, info);
    scene[1].button[3].callback = &fill_map_t_one;
    init_buttonturrettwo(&scene[1].button[4], pos_buyturrettwo, size_turret, info);
    scene[1].button[4].callback = &fill_map_t_two;
    init_buttonwall(&scene[1].button[5], pos_buyturretthree, size_turret, info);
    scene[1].button[5].callback = &fill_map_t_three;
    init_buttonturretfour(&scene[1].button[6], pos_buyturretfour, size_turret, info);
    scene[1].button[6].callback = &nuclear_func;
}