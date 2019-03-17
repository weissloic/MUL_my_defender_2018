/*
** EPITECH PROJECT, 2019
** setup2.c
** File description:
** setup sprites and textures for defender
*/

#include "../../include/runner.h"

void setup_texturestwo(info_t *info)
{
    info->wall_textureresize = sfTexture_createFromFile(
    "ressources/wallresize.png", NULL);
    info->sign_price_texture = sfTexture_createFromFile(
    "ressources/sign_price.png", NULL);
    info->nuke_explosion = sfTexture_createFromFile(
    "ressources/nuclearsprite.png", NULL);
    info->test_image = sfSprite_create();
    info->dollar = sfSprite_create();
    info->shophouse = sfSprite_create();
    info->shopmenu = sfSprite_create();
    info->explosion = sfSprite_create();
    info->sign_price_sprite_1 = sfSprite_create();
    info->sign_price_sprite_2 = sfSprite_create();
    info->sign_price_sprite_3 = sfSprite_create();
    info->sign_price_sprite_4 = sfSprite_create();
    info->pause_sprite = sfSprite_create();
    info->castle_sprite = sfSprite_create();
    info->clock = sfClock_create();
    info->score = sfClock_create();
    setup_score(info);
    info->menu_turret = 0;
    setup_prices(info);
    create_music(info);
}

void set_texturestwo(info_t *info, scene_t *scene)
{
    sfSprite_setTexture(scene[4].background, info->game_bg, sfFalse);
    sfSprite_setTexture(info->test_image, info->test, sfFalse);
    sfSprite_setTexture(info->dollar, info->dollar_texture, sfFalse);
    sfSprite_setTexture(info->shophouse, info->shop_house, sfFalse);
    sfSprite_setTexture(info->shopmenu, info->menu_shop, sfFalse);
    sfSprite_setTexture(info->pause_sprite, info->pause_texture, sfFalse);
    sfSprite_setTexture(info->castle_sprite, info->castle_texture, sfFalse);
    sfSprite_setPosition(info->castle_sprite, info->castle_position);
    sfSprite_setPosition(info->shopmenu, info->shopmenu_pos);
    sfSprite_setPosition(info->dollar, info->money_pos);
    sfSprite_setPosition(info->shophouse, info->shophouse_pos);
    sfSprite_setPosition(scene[0].background_mainmenu, info->initial_parallax);
    sfSprite_setPosition(info->sign_price_sprite_1, info->sign_price_pos1);
    sfSprite_setPosition(info->sign_price_sprite_2, info->sign_price_pos2);
    sfSprite_setPosition(info->sign_price_sprite_3, info->sign_price_pos3);
    sfSprite_setPosition(info->sign_price_sprite_4, info->sign_price_pos4);
}

void setup_scene_2_buttons(scene_t *scene, info_t *info)
{
    sfVector2f size2 = {90, 90};
    sfVector2f pos_buyturrettwo = {250, 250};
    sfVector2f pos_buyturretthree = {400, 250};
    sfVector2f pos_shop = {100, 250};
    sfVector2f pos_buyturretfour = {550, 250};
    sfVector2f pos_gotogame = {0, 0};

    init_buttonturretone(&scene[2].button[0], pos_shop, size2, info);
    scene[2].button[0].callback = &price_turretone;
    init_buttonturrettwo(&scene[2].button[1], pos_buyturrettwo, size2, info);
    scene[2].button[1].callback = &price_turrettwo;
    init_buttonwall(&scene[2].button[2], pos_buyturretthree, size2, info);
    scene[2].button[2].callback = &price_turretthree;
    init_buttonturretfour(&scene[2].button[3], pos_buyturretfour, size2, info);
    scene[2].button[3].callback = &price_nuclear;
    init_button_gobackgame(&scene[2].button[4], pos_gotogame, size2, info);
    scene[2].button[4].callback = &goto_game;
}

void setup_scene_4_buttons(scene_t *scene, info_t *info)
{
    sfVector2f size2 = {90, 90};
    sfVector2f pos_buyturrettwo = {360, 240};
    sfVector2f pos_buyturretthree = {360, 325};
    sfVector2f pos_buyturretfour = {360, 440};

    init_buttonpauseresume(&scene[4].button[0], pos_buyturrettwo, size2, info);
    scene[4].button[0].callback = &goto_game;
    init_buttonpausebackmenu(&scene[4].button[1], pos_buyturretthree, size2, info);
    scene[4].button[1].callback = &goto_menu;
    init_buttonupsound(&scene[4].button[2], pos_buyturretfour, size2, info);
    scene[4].button[2].callback = &exit_window;
}