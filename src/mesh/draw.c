/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "world.h"

void draw_line(vertex_t vertxs[3], win_t *win)
{
    win->tmp->position = (sfVector2f){vertxs[1].pos[0], vertxs[1].pos[1]};
    sfVertexArray_append(win->array, *win->tmp);
    win->tmp->position = (sfVector2f){vertxs[2].pos[0], vertxs[2].pos[1]};
    sfVertexArray_append(win->array, *win->tmp);
    win->tmp->position = (sfVector2f){vertxs[0].pos[0], vertxs[0].pos[1]};
    sfVertexArray_append(win->array, *win->tmp);
}

void draw_triangle(vertex_t vertxs[3], triangle_t *tri, win_t *win)
{
    win->tmp->color = center_vertxs(vertxs, tri, win);
    for (int i = 0; i < 3; i++) {
        win->tmp->position = (sfVector2f) {vertxs[i].pos[0], vertxs[i].pos[1]};
        if (IS_BLUE(tri->color))
            win->tmp->texCoords = water[i];
        if (IS_GREEN(tri->color))
            win->tmp->texCoords = grass[i];
        if (IS_WHITE(tri->color))
            win->tmp->texCoords = snow[i];
        sfVertexArray_append(win->array, *win->tmp);
    }
    if (win->params->is_outline)
        draw_line(vertxs, win);
}

void fill_pts(vertex_t pts[3], vertex_t *vertxs, int *index)
{
    pts[0] = vertxs[index[0]];
    pts[1] = vertxs[index[1]];
    pts[2] = vertxs[index[2]];
}

void draw_meshes(world_t *world, win_t *win)
{
    size_t i = -1;
    vertex_t pts[3];
    project_meshes(world, win->params->zoom);
    sort_vertxs(world);
    if (!win->params->pause && sfClock_getElapsedTime(world->clock)
    .microseconds / 1000000.0 > 0.02)
        move_light(world, win);
    if (world->light_source[2] > 0)
        draw_light(world, win);
    while ((i += 1) < world->nb_trig) {
        fill_pts(pts, world->projected, world->sortBuffer[i].data->vertxs);
        if (pts[0].pos[2] > 0 || pts[1].pos[2] > 0 || pts[2].pos[2] > 0)
            continue;
        if (get_direction(pts) >= 0)
            draw_triangle(pts, world->sortBuffer[i].data, win);
    }
    sfVertexArray_setPrimitiveType(win->array, win->params->is_outline ?
    sfLines : sfTriangles);
    sfRenderTexture_drawVertexArray(win->r_tex, win->array, win->states);
    sfVertexArray_clear(win->array);
}
