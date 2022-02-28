/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create.c
*/

#include "menus.h"

// sfRectangleShape *rectangle_from_texture(sfTexture const *tex)
// {
//     sfRectangleShape *r = sfRectangleShape_create();

//     sfRectangleShape_setTexture(r, tex, 0);
//     return r;
// }

// char *file_name(char const *path)
// {
//     int last_slash = -1;

//     for (int i = 0; path[i]; i++)
//         if (path[i] == '/')
//             last_slash = i;
//     return path + last_slash + 1;
// }

// void rescale_map(map_t *m, sfVector2f win_size)
// {
//     double height = win_size.y * MAP_Y_FACTOR;

//     sfRenderTexture_destroy(m->rtex);
//     m->rtex = sfRenderTexture_create(win_size.x * MAP_X_FACTOR, height, 0);
//     sfText_setCharacterSize(m->name, win_size.y * MAIN_MENU_TXT_FACTOR);
//     set_sprite_size(m->thumbnail, (sfVector2f){height, height});
//     sfText_setPosition(m->name, (sfVector2f){height * 1.12, height * 0.5});
// }

// sfRectangleShape *map_sprite(map_t *m)
// {
//     sfRenderTexture_clear(m->rtex, sfBlack);
//     sfRenderTexture_drawSprite(m->rtex, m->thumbnail, NULL);
//     sfRenderTexture_drawText(m->rtex, m->name, NULL);
//     sfRenderTexture_display(m->rtex);
//     return rectangle_from_texture(sfRenderTexture_getTexture(m->rtex));
// }

// map_t *create_map(sfVector2f win_size, char const *file)
// {
//     map_t *map = malloc(sizeof(map_t));
//     double height = win_size.y * MAP_Y_FACTOR;

//     map->rtex = sfRenderTexture_create(win_size.x * MAP_X_FACTOR, height, 0);
//     map->name = init_text(file_name(file), win_size.y * MAIN_MENU_TXT_FACTOR);
//     map->file = file;
//     center_text(map->name);
//     map->thumbnail = init_sprite(global_texture(),
//     thumbnail_rect, (sfVector2f){height, height});
//     rescale_map(map, win_size);
//     return map;
// }
