/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** create.c
*/

#include "menus.h"
#include "list.h"
#include "map_select.h"

void destroy_map_select(map_select_t *map)
{
    for (int i = 0; i < 3; i++)
        destroy_button(map->buttons[i]);
    sfSprite_destroy(map->background);
    sfRenderTexture_destroy(map->rtex);
    for (; map->maps;)
        remove_node(&map->maps, 0, &destroy_entry);
    sfRectangleShape_destroy(map->box);
    sfSprite_destroy(map->hider);
    sfClock_destroy(map->double_click);
    free(map);
}

void scale_entry(map_entry_t *entry, sfVector2f size)
{
    sfFloatRect sp_bnds;

    sfRenderTexture_destroy(entry->rtex);
    entry->rtex = sfRenderTexture_create(size.x, size.y, false);
    set_sprite_size(entry->icon, (sfVector2f){size.y, size.y});

    sp_bnds = sfSprite_getGlobalBounds(entry->icon);
    sfText_setCharacterSize(entry->level_name, size.y * 0.6);
    sfText_setPosition(entry->level_name,
    (sfVector2f){sp_bnds.width * 1.1, size.y * 0.2});
}

void scale_entries(map_select_t *m, sfVector2f size)
{
    list_t *tmp = m->maps;

    if (!tmp)
        return;
    do {
        scale_entry(tmp->data, (sfVector2f){size.x, size.y * ENTRY_Y_SPAN});
        tmp = tmp->next;
    } while (tmp != m->maps);
}

void scale_select(map_select_t *m, sfVector2f size)
{
    sfVector2f pos;

    m->size = size;
    sfRenderTexture_destroy(m->rtex);
    m->rtex = sfRenderTexture_create(size.x, size.y, 0);
    for (int i = 0; i < 3; i++) {
        pos = (sfVector2f){size.x * select_pf[i][0], size.y * select_pf[i][1]};
        m->buttons[i]->pos = pos;
        sfSprite_setPosition(m->buttons[i]->sprite, pos);
        m->buttons[i]->size =
        (sfVector2f){size.x * select_sf[0], size.y * select_sf[1]};
        set_sprite_size(m->buttons[i]->sprite, m->buttons[i]->size);
        sfText_setCharacterSize(m->buttons[i]->text, size.y * 0.07);
    }
    set_sprite_size(m->hider, (sfVector2f){size.x * 0.1, size.x * 0.1});
    sfSprite_setPosition(m->hider, (sfVector2f){0, size.y * 0.8});
    scale_entries(m, size);
}

map_select_t *create_map_select(sfVector2f size)
{
    map_select_t *m = malloc(sizeof(map_select_t));
    m->rtex = sfRenderTexture_create(size.x, size.y, false);
    m->maps = NULL;
    for (int i = 0; i < 3; i++) {
        m->buttons[i] = init_button(global_texture(), but_rects[i],
        (sfVector2f){0, 0}, (sfVector2f){size.x * select_sf[0],
        size.y * select_sf[1]}, ms_but_txt[i], NULL);
        center_sprite(m->buttons[i]->sprite);
    }
    m->size = size;
    m->background = init_sprite(global_texture(), background_rect, size);
    m->box = sfRectangleShape_create();
    m->hider = init_sprite(global_texture(),
    hider_rect, (sfVector2f){size.x * 0.1, size.x * 0.1});
    m->primary = -1;
    init_entries(m, size);
    scale_select(m, size);
    m->secondary = -1;
    m->x_start = 0;
    return m;
}
