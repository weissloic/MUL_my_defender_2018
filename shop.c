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
    sfRectangleShape_setTexture(button->rect_turretfour, info->nuke_logo, 0);
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

void setup_prices(info_t *info)
{
    setup_price_turretone(info);
    setup_price_turrettwo(info);
    setup_price_turretthree(info);
    setup_price_nuke(info);
}

void setup_price_turretone(info_t *info)
{
    char *price = "20$";
    sfVector2f price_pos = {175, 400};
    info->turret_one = sfText_create();
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->turret_one, info->font);
    sfText_setPosition(info->turret_one, price_pos);
    sfText_setString(info->turret_one, price);
}

void setup_price_turrettwo(info_t *info)
{
    char *price = "50$";
    sfVector2f price_pos = {325, 400};
    info->turret_two = sfText_create();
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->turret_two, info->font);
    sfText_setPosition(info->turret_two, price_pos);
    sfText_setString(info->turret_two, price);
}

void setup_price_turretthree(info_t *info)
{
    char *price = "75$";
    sfVector2f price_pos = {475, 400};
    info->turret_three = sfText_create();
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->turret_three, info->font);
    sfText_setPosition(info->turret_three, price_pos);
    sfText_setString(info->turret_three, price);
}

void setup_price_nuke(info_t *info)
{
    char *price = "500$";
    sfVector2f price_pos = {625, 400};
    info->nuke_price = sfText_create();
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->nuke_price, info->font);
    sfText_setPosition(info->nuke_price, price_pos);
    sfText_setString(info->nuke_price, price);
}