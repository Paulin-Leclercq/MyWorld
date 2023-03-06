/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** spectator_create.c
*/

#include "menus.h"

void destroy_spectator(spectator_t *s)
{
    sfClock_destroy(s->time);
    s->win->destroy(s->win);
    s->world->destroy(s->world);
    free(s);
}

void move_spectator(mat4x4 **mat_world, spectator_t *s)
{
    mat4x4 *tmp;
    mat4x4 *mat_mov;

    if (sfClock_getElapsedTime(s->time).microseconds < SPECTATOR_TIME)
        return;
    sfClock_restart(s->time);
    mat_mov = mat4x4_ry(PI / 360);
    if (mat_mov) {
        tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);
        mat4x4_destroy(mat_mov);
        mat4x4_destroy(*mat_world);
        *mat_world = tmp;
    }
}

void center_cam(mat4x4 **mat_world)
{
    float vec[3] = {48, -10, 48};
    mat4x4 *mat_mov = mat4x4_t(vec);
    mat4x4 *tmp = mat4x4_multiplymat4x4(*mat_world, mat_mov);

    mat4x4_destroy(mat_mov);
    mat4x4_destroy(*mat_world);
    *mat_world = tmp;
}

void draw_spectator_to_rtex(spectator_t *s,
sfRenderTexture *rtex, sfBool dark, sfBool update)
{
    sfSprite *sp;
    sfVector2u size = sfRenderTexture_getSize(rtex);
    if (update)
        move_spectator(&(s->world->matrix), s);
    sfRenderTexture_clear(s->win->r_tex, sfBlack);
    draw_back(s->world, s->win);
    draw_meshes(s->world, s->win);
    sfRenderTexture_display(s->win->r_tex);
    sp = init_sprite_from_texture(sfRenderTexture_getTexture(s->win->r_tex));
    if (dark)
        sfSprite_setColor(sp, SEMI_COLOR);
    center_sprite(sp);
    sfSprite_setPosition(sp, (sfVector2f){size.x / 2.0, size.y / 2.0});
    sfRenderTexture_drawSprite(rtex, sp, NULL);
    sfSprite_destroy(sp);
}

spectator_t *create_spectator(sfVector2f size)
{
    spectator_t *s = malloc(sizeof(spectator_t));
    world_t *world;
    float size_x = MIN(size.x, size.y);

    s->world = create_world();
    world = s->world;
    create_map(world, SPECTATOR_SIZE);
    set_light_source(world, SPECTATOR_SIZE / 2.0, 1, 1000);
    convert_to_array(world);
    world->sortBuffer = malloc(sizeof(vecsort_t) * world->nb_trig);
    world->sortBuffer2 = malloc(sizeof(vecsort_t) * world->nb_trig);
    s->win = win_create(world->nb_trig, (sfVector2f){size_x, size_x});
    s->win->map_size = SPECTATOR_SIZE;
    get_gradient(1);
    smooth_shadow(world, s->win);
    free_lists(world);
    center_cam(&(s->world->matrix));
    s->time = sfClock_create();
    return s;
}
