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
    info->seconds = sfClock_getElapsedTime(info->clock).SEC;

    set_textures(info, scene);

    //my_loading_screen(info, scene);

    while (sfRenderWindow_isOpen(info->window)) {
        while (sfRenderWindow_pollEvent(info->window, &info->event)) {
            analyse_events(info, scene, button);
        }


        if (info->view == 1) {
            analyse_time(info);
            move_monster_time(info, scene);
            sfRenderWindow_drawSprite(info->window, scene[1].background, NULL);
            sfRenderWindow_drawSprite(info->window, scene[1].monster, NULL);
            sfRenderWindow_drawRectangleShape(info->window, scene[1].button[0].rect_pause, NULL);
            

        }

        //
        //sfRenderWindow_drawRectangleShape(info->window, scene[1].button[1].rect, NULL);


        if (info->view == 0) {
            //for (int i = 0; scene[info->view].button[i].rect != NULL; i++) {
                sfRenderWindow_drawSprite(info->window, scene[0].background, NULL);
                //sfRenderWindow_drawSprite(info->window, scene[0].monster, NULL);
                sfRenderWindow_drawRectangleShape(info->window, scene[0].button[0].rect, NULL);
                sfRenderWindow_drawRectangleShape(info->window, scene[0].button[1].rect_two, NULL);
                sfRenderWindow_drawRectangleShape(info->window, scene[0].button[2].rect_three, NULL);
            //}
        }

        
        print_score(info);
        sfRenderWindow_display(info->window);
        sfRenderWindow_clear(info->window, sfBlack);
    }
}


void my_loading_screen(info_t *info, scene_t *scene)
{
    for (int i = 1; i != 180; i++) {
        for (int y = 0; y != 10; y++) {
            char *test = my_itoa(i);
            char str[] = "loadingscreen/sprite";
            char png[] = ".png";
            my_strcat(str, test);
            my_strcat(str, png);
            info->loadingscreen_bg = sfTexture_createFromFile(str, NULL);
            sfSprite_setTexture(scene[3].background, info->loadingscreen_bg, sfFalse);
            sfRenderWindow_drawSprite(info->window, scene[3].background, NULL);
            sfRenderWindow_display(info->window);
            if (i != 179)
                sfTexture_destroy(info->loadingscreen_bg);
        }
    }
    info->view = 0;
}


void analyse_time(info_t *info)
{
    float time = sfClock_getElapsedTime(info->score).SEC;

    if (time > 1) {
        info->score_int++;
        sfClock_restart(info->score);
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
   //     printf("x is %f\n", info->new_pos.x);
    //    printf("y is = %f\n", info->new_pos.y);
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

int button_is_clickedtwo(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_two);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_is_clickedtower(button_t button, sfVector2i click_position)
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

int button_is_clickedthree(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_three);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_is_clickedpause(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pause);

    if (click_position.x >= button_pos.x && 200 &&
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

void put_in_pause(info_t *info)
{
    info->view = 0;
}

void play(info_t *info)
{
    info->view++;
    printf("%d\n", info->view);
}

/*void move_towerbutton(info_t *info, button_t *button)
{
    info->menu_turret = 1;
    info->temp_pos_for_menu.x = 250;
    info->temp_pos_for_menu.y = 250;
    //sfSprite_setPosition()
    printf("%d\n", info->menu_turret);
}*/

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