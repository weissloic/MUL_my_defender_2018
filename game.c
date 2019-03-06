/*
** EPITECH PROJECT, 2018
** bootstrap_runner.c
** File description:
** bootstrap for my_runner
*/

#include "include/runner.h"

void game(player_t *player, info_t *info, scene_t *scene, button_t *button)
{
    sfVideoMode mode = {800, 600, 32};
    info->window = sfRenderWindow_create(mode, "jeu", sfResize | sfClose, NULL);
    info->view = 0;
    info->new_pos.x = 0;
    info->new_pos.y = 35;
    set_textures(info, scene);


    while (sfRenderWindow_isOpen(info->window)) {
        while (sfRenderWindow_pollEvent(info->window, &info->event)) {
            analyse_events(info, scene, button);
            }
        if (info->view == 1)
            move_monster_time(info, scene);
        sfRenderWindow_drawSprite(info->window, scene[info->view].background, NULL);
        sfRenderWindow_drawSprite(info->window, scene[info->view].background, NULL);
        sfRenderWindow_drawSprite(info->window, scene[info->view].monster, NULL);
        sfRenderWindow_drawRectangleShape(info->window, scene[info->view].button[1].rect_two, NULL);
        for (int i = 0; scene[info->view].button[i].rect != NULL; i++) {
            sfRenderWindow_drawRectangleShape(info->window, scene[info->view].button[i].rect, NULL);
            //
        }
        sfRenderWindow_display(info->window);
        sfRenderWindow_clear(info->window, sfBlack);
    }
}

void move_monster_time(info_t *info, scene_t *scene)
{
    info->seconds = sfClock_getElapsedTime(info->clock).SEC;

    if (info->seconds > 0.01) {
        

        if (info->new_pos.x == 150 && info->new_pos.y == 40) {
            info->new_pos.y = 40;
            info->new_pos.x += 10;
        }
        else if (info->new_pos.x == 150) {
            info->new_pos.x = 150;
            info->new_pos.y += 2;
        }
        else
            info->new_pos.x += 2;
        printf("x is %f\n", info->new_pos.x);
        printf("y is = %f\n", info->new_pos.y);
        sfSprite_setPosition(scene[1].monster, info->new_pos);
        sfClock_restart(info->clock);
    }
}


int button_is_clicked(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

void exit_window(info_t *info)
{
    sfRenderWindow_close(info->window);
}

void play(info_t *info)
{
    info->view++;
    printf("%d\n", info->view);
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