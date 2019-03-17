/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

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

void init_buttonwall(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
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
    sfRectangleShape_setTexture(button->rect_turretfour, info->nuke_logo, 0);
}