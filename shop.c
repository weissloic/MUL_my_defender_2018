/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/runner.h"

void init_buttonshop(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_shop = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_shop, position);
    sfRectangleShape_setSize(button->rect_shop, size);
    sfRectangleShape_setTexture(button->rect_shop, info->button_normal, 0);
}

void init_buttonturretone(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_turretone = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_turretone, position);
    sfRectangleShape_setSize(button->rect_turretone, size);
    sfRectangleShape_setTexture(button->rect_turretone, info->button_normal, 0);
}

void init_buttonturrettwo(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_turrettwo = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_turrettwo, position);
    sfRectangleShape_setSize(button->rect_turrettwo, size);
    sfRectangleShape_setTexture(button->rect_turrettwo, info->button_normal, 0);
}

void init_buttonturretthree(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_turretthree = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_turretthree, position);
    sfRectangleShape_setSize(button->rect_turretthree, size);
    sfRectangleShape_setTexture(button->rect_turretthree, info->button_normal, 0);
}

void init_buttonturretfour(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_turretfour = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_turretfour, position);
    sfRectangleShape_setSize(button->rect_turretfour, size);
    sfRectangleShape_setTexture(button->rect_turretfour, info->button_normal, 0);
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

int button_buy_turretone(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretone);

    if (click_position.x >= button_pos.x && 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_buy_turrettwo(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turrettwo);

    if (click_position.x >= button_pos.x && 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_buy_turretthree(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretthree);

    if (click_position.x >= button_pos.x && 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_buy_turretfour(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_turretfour);

    if (click_position.x >= button_pos.x && 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}