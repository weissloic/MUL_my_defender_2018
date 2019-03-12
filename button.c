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

void init_buttonptinpause(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_putinpause = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_putinpause, position);
    sfRectangleShape_setSize(button->rect_putinpause, size);
    sfRectangleShape_setTexture(button->rect_putinpause, info->button_normal, 0);
}

void init_buttonpauseresume(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_pausresume = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_pausresume, position);
    sfRectangleShape_setSize(button->rect_pausresume, size);
    sfRectangleShape_setTexture(button->rect_pausresume, info->button_normal, 0);
}

void init_buttonpausebackmenu(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_pausbackmenu = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_pausbackmenu, position);
    sfRectangleShape_setSize(button->rect_pausbackmenu, size);
    sfRectangleShape_setTexture(button->rect_pausbackmenu, info->button_normal, 0);
}

void init_buttonupsound(button_t *button, sfVector2f position, sfVector2f size, info_t *info)
{
    button->rect_pausupsound = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect_pausupsound, position);
    sfRectangleShape_setSize(button->rect_pausupsound, size);
    sfRectangleShape_setTexture(button->rect_pausupsound, info->button_normal, 0);
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

int put_in_pausegame(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_putinpause);

    if (click_position.x >= button_pos.x && 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_is_clickedresume(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pausresume);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_is_clickedsound(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pausupsound);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}

int button_is_clickedbackmenu(button_t button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button.rect_pausbackmenu);

    if (click_position.x >= button_pos.x &&
        click_position.x <= button_pos.x + 200 &&
        click_position.y >= button_pos.y &&
        click_position.y <= button_pos.y + 100)
        return (1);
    else
        return (0);
}