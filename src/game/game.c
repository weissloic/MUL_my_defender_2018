/*
** EPITECH PROJECT, 2018
** bootstrap_runner.c
** File description:
** bootstrap for my_runner
*/

#include "../../include/runner.h"

void draw_two(info_t *info, scene_t *scene)
{
    sfRenderWindow_drawSprite(info->window, info->shopmenu, NULL);
    sfRenderWindow_drawSprite(info->window, info->dollar, NULL);
    sfRenderWindow_drawSprite(info->window, info->shophouse, NULL);
    sfRenderWindow_drawSprite(info->window, info->sign_price_sprite_1, NULL);
    sfRenderWindow_drawSprite(info->window, info->sign_price_sprite_2, NULL);
    sfRenderWindow_drawSprite(info->window, info->sign_price_sprite_3, NULL);
    sfRenderWindow_drawSprite(info->window, info->sign_price_sprite_4, NULL);
    sfRenderWindow_drawText(info->window, info->turret_one, NULL);
    sfRenderWindow_drawText(info->window, info->turret_two, NULL);
    sfRenderWindow_drawText(info->window, info->turret_three, NULL);
    sfRenderWindow_drawText(info->window, info->nuke_price, NULL);
}

void my_view_four(info_t *info, scene_t *scene)
{
    info->switch_scene = 1;
    sfMusic_play(info->main_music);
    sfRenderWindow_drawSprite(info->window, scene[4].background, NULL);
    sfRenderWindow_drawRectangleShape(info->window,
    scene[4].button[0].rect_pausresume, NULL);
    sfRenderWindow_drawRectangleShape(info->window,
    scene[4].button[1].rect_pausbackmenu, NULL);
    sfRenderWindow_drawRectangleShape(info->window,
    scene[4].button[2].rect_pausupsound, NULL);
    sfRenderWindow_drawSprite(info->window, info->pause_sprite, NULL);
}

void my_diff_view(info_t *info, scene_t *scene)
{
        if (info->view == 1)
            my_view_one(info, scene);
        if (info->view == 0)
            my_view_null(info, scene);
        if (info->view == 2)
            my_view_two(info, scene);
        if (info->view == 4)
            my_view_four(info, scene);
}

void game(player_t *player, info_t *info, scene_t *scene, button_t *button)
{
    sfVideoMode mode = {800, 600, 32};
    info->window = sfRenderWindow_create(mode, "jeu", sfResize | sfClose, NULL);
    init_valuethree(info);
    sfRenderWindow_setVerticalSyncEnabled(info->window, sfTrue);
    set_textures(info, scene);
    sfMusic_setLoop(info->main_music, sfTrue);
    sfMusic_play(info->main_music);
    my_loading_screen(info, scene);

    while (sfRenderWindow_isOpen(info->window)) {
        while (sfRenderWindow_pollEvent(info->window, &info->event)) {
            analyse_events(info, scene, button);
        }

        my_diff_view(info, scene);

        sfRenderWindow_display(info->window);
        sfRenderWindow_clear(info->window, sfBlack);
    }
    destroy_music(info);
}

int main(int ac, char **av)
{
    player_t *player = malloc(sizeof(player_t));
    info_t *info = malloc(sizeof(info_t));
    scene_t *scene = init_scenes(info);
    button_t *button = malloc(sizeof(button_t));

    setup_textures(info);
    game(player, info, scene, button);
    return (0);
}