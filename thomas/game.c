/*
** EPITECH PROJECT, 2018
** bootstrap_runner.c
** File description:
** bootstrap for my_runner
*/

#include "include/runner.h"

void game(player_t *player, info_t *info, scene_t *scene)
{
    sfVideoMode mode = {800, 600, 32};
    info->window = sfRenderWindow_create(mode, "jeu", sfResize | sfClose, NULL);
    info->view = 0;

    while (sfRenderWindow_isOpen(info->window)) {
        for (int i = 0; scene[info->view].button[i].rect != NULL; i++)
            sfRenderWindow_drawRectangleShape(info->window, scene[info->view].button[i].rect, NULL);
        sfRenderWindow_display(info->window);
        while (sfRenderWindow_pollEvent(info->window, &info->event)) {
            analyse_events(info, scene);
        }
    sfRenderWindow_clear(info->window, sfBlack);
    }
}


void print_hello()
{
    printf("Hello\n");
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

scene_t *init_scenes()
{
    sfVector2f pos = {100, 100};
    sfVector2f size = {200, 100};
    sfVector2f pos2 = {300, 100};
    scene_t *scene = malloc(sizeof(scene_t) * 2);

    scene[0].button = malloc(sizeof(button_t) * 2);
    scene[1].button = malloc(sizeof(button_t) * 3);
    init_button(&scene[0].button[0], pos, size);
    scene[0].button[0].callback = &play;
    init_button(&scene[0].button[1], pos2, size);
    scene[0].button[1].callback = &exit_window;

    return(scene);
}

void init_button(button_t *button, sfVector2f position, sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setFillColor(button->rect, sfRed);
}

int main(int ac, char **av)
{
    player_t *player = malloc(sizeof(player_t));
    info_t *info = malloc(sizeof(info_t));
    scene_t *scene = init_scenes();

    game(player, info, scene);
    return (0);
}