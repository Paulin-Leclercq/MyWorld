/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** background
*/

#include "world.h"

void add_background(world_t *world)
{
    sfConvexShape *back = sfConvexShape_create();

    sfConvexShape_setPointCount(back, 4);
    sfConvexShape_setPoint(back, 0, (sfVector2f){0, 0});
    sfConvexShape_setPoint(back, 1, (sfVector2f){5000, 0});
    sfConvexShape_setPoint(back, 2, (sfVector2f){5000, 5000});
    sfConvexShape_setPoint(back, 3, (sfVector2f){0, 5000});
    world->back = back;
}

void draw_back(world_t *world, win_t *win)
{
    float mid = world->moy_dir / world->nb_trig;
    sfColor color = {119 * mid, 181 * mid, 254 * mid, 255};
    sfConvexShape_setFillColor(world->back, color);
    sfRenderTexture_drawConvexShape(win->r_tex, world->back, 0);
}
