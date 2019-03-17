/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/runner.h"

void pos_inventorytwo(info_t *info, scene_t *scene)
{
    if (info->fill_turrettwo == 1)
        func2_create_turrettwo(info, scene);
    if (info->get_turretthree == 1)
        func3_create_turret(info, scene);
    if (info->fill_turretthree == 1)
        func3_create_turrettwo(info, scene);
}