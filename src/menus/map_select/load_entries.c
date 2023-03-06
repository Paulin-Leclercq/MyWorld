/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** load_entries.c
*/

#include "menus.h"

void destroy_entry(void *entry)
{
    map_entry_t *e = entry;

    sfSprite_destroy(e->icon);
    sfRenderTexture_destroy(e->rtex);
    sfText_destroy(e->level_name);
    free(e);
}

sfSprite *init_entry_icon(char const *path, sfVector2f icon_size)
{
    sfTexture *t = sfTexture_createFromFile(path, NULL);
    sfSprite *s;

    if (!t)
        return init_sprite(global_texture(), icon_rect, icon_size);
    add_texture(t);
    s = init_sprite_from_texture(t);
    set_sprite_size(s, icon_size);
    return s;
}

list_t *get_all_levels_name(void)
{
    DIR *dir = opendir("./map/");
    list_t *levels = NULL;
    char *tmp;
    dirent_t *t;

    if (!dir)
        return NULL;
    while ((t = readdir(dir))) {
        tmp = str_concat(2, "./map/", t->d_name);
        if (is_file_valid(tmp))
            append_node(&levels, my_strdup(t->d_name));
        free(tmp);
    }
    closedir(dir);
    return levels;
}

map_entry_t *create_entry(char const *file, sfVector2f size)
{
    map_entry_t *e = malloc(sizeof(map_entry_t));
    char *entry_png = str_concat(3, "./map/.", file, ".png");

    e->rtex = sfRenderTexture_create(size.x, size.y, false);
    e->icon = init_entry_icon(entry_png, (sfVector2f){size.y, size.y});
    e->level_name = init_text(file, size.y * 0.9);
    free(entry_png);
    scale_entry(e, size);
    return e;
}

void init_entries(map_select_t *m, sfVector2f size)
{
    list_t *tmp = get_all_levels_name();

    while (m->maps)
        remove_node(&m->maps, 0, &destroy_entry);
    while (tmp) {
        append_node(&(m->maps), create_entry(tmp->data,
        (sfVector2f){size.x, size.y * ENTRY_Y_SPAN}));
        remove_node(&tmp, 0, &free);
    }
    for (int i = 0; i < 3; i++) {
        sfSprite_setColor(m->buttons[i]->sprite,
        (!i || m->primary >= 0) ? sfWhite : SEMI_COLOR);
        sfText_setColor(m->buttons[i]->text,
        (!i || m->primary >= 0) ? sfWhite : SEMI_COLOR);
    }
    m->double_click = sfClock_create();
}
