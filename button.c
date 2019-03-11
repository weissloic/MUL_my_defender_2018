/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button
*/

#include "include/runner.h"

void init_button(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTextureRect(button->rect, info->start_rect);
}

void init_buttontwo(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_two = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_two, position);
    sfRectangleShape_setSize(button->rect_two, size);
    sfRectangleShape_setTexture(button->rect_two, info->button_normal, 0);
}

void init_buttonthree(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_three = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_three, position);
    sfRectangleShape_setSize(button->rect_three, size);
    sfRectangleShape_setTexture(button->rect_three, info->button_normal, 0);
}

void init_buttonupgrade(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_pause = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect_pause, size);
    sfRectangleShape_setTexture(button->rect_pause, info->second_button_normal, 0);
}

void init_buttontower(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfRed);
}

void init_buttonshop(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_shop = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_shop, position);
    sfRectangleShape_setSize(button->rect_shop, size);
    sfRectangleShape_setTexture(button->rect_shop, info->button_normal, 0);
}

void coupe_decale(info_t *info)
{
    info->menu_turret = 1;
    printf("%d\n", info->menu_turret);
}

void exit_turret_menu(info_t *info)
{
    info->menu_turret = 0;
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

int button_is_clickedshop(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_shop);

    if (click_position.x >= button_pos.x && 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}