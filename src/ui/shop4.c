/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void setup_price_turretone(info_t *info)
{
    char *price = "20$";
    sfVector2f price_pos = {130, 375};
    info->turret_one = sfText_create();
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->turret_one, info->font);
    sfText_setPosition(info->turret_one, price_pos);
    sfText_setString(info->turret_one, price);
}

void setup_price_turrettwo(info_t *info)
{
    char *price = "50$";
    sfVector2f price_pos = {280, 375};
    info->turret_two = sfText_create();
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->turret_two, info->font);
    sfText_setPosition(info->turret_two, price_pos);
    sfText_setString(info->turret_two, price);
}

void setup_price_wall(info_t *info)
{
    char *price = "75$";
    sfVector2f price_pos = {430, 375};
    info->turret_three = sfText_create();
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->turret_three, info->font);
    sfText_setPosition(info->turret_three, price_pos);
    sfText_setString(info->turret_three, price);
}

void setup_price_nuke(info_t *info)
{
    char *price = "500$";
    sfVector2f price_pos = {575, 375};
    info->nuke_price = sfText_create();
    info->font = sfFont_createFromFile("ressources/font.TTF");
    sfText_setFont(info->nuke_price, info->font);
    sfText_setPosition(info->nuke_price, price_pos);
    sfText_setString(info->nuke_price, price);
}

void check_gobacktogame(button_t button, sfVector2i mouse_pos, info_t *info)
{
    sfVector2f button_pos;
    button_pos = sfRectangleShape_getPosition(button.rect_gobackgame);
    if (mouse_pos.x >= button_pos.x &&
        mouse_pos.x <= button_pos.x + 70 &&
        mouse_pos.y >= button_pos.y &&
        mouse_pos.y <= button_pos.y + 80) {
        sfRectangleShape_setTexture(button.rect_gobackgame,
        info->second_button_hover, 0);
    }
    else {
        info->start_rect.left = 140;
        info->start_rect.top = 80;
        info->start_rect.width = 70;
        info->start_rect.height = 80;
        sfRectangleShape_setTextureRect(button.rect_gobackgame,
        info->start_rect);
        sfRectangleShape_setTexture(button.rect_gobackgame,
        info->second_button_normal, 0);
    }
}