/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** events.c
*/

#include "menus.h"
#include "my.h"
#include "line_edit.h"

const char *get_text(line_edit_t *le)
{
    char const *r;

    if (le->has_underscore)
        remove_last_text(le->text);
    r = sfText_getString(le->text);
    if (le->has_underscore)
        append_to_text(le->text, ' ');
    return r;
}

void append_to_text(sfText *t, char c)
{
    char const *base = sfText_getString(t);
    int const base_len = my_strlen(base);
    char *new = malloc(sizeof(char) * (base_len + 2));

    my_strcpy(new, base);
    new[base_len] = c;
    new[base_len + 1] = 0;
    sfText_setString(t, new);
    free(new);
}

void remove_last_text(sfText *t)
{
    char const *base = sfText_getString(t);
    int const base_len = my_strlen(base);
    char *new;

    if (!base_len)
        return;
    new = malloc(sizeof(char) * (base_len));
    for (int i = 0; i < base_len - 1; i++)
        new[i] = base[i];
    new[base_len - 1] = 0;
    sfText_setString(t, new);
    free(new);
}

void append_ev(sfEvent ev, sfText *base)
{
    int code = ev.key.code;

    if (code <= sfKeyZ && code >= sfKeyA)
        append_to_text(base, codes[code]);
    if (code == sfKeyNum8 && !ev.key.shift)
        append_to_text(base, '_');
    if (code == sfKeyHyphen)
        append_to_text(base, ev.key.shift ? '6' : '-');
    if (code == sfKeyQuote && ev.key.shift)
        append_to_text(base, '4');
    if (ev.key.shift && code >= sfKeyNum0 && code <= sfKeyNum9)
        append_to_text(base, digits[code - sfKeyNum0]);
    if (code >= sfKeyNumpad0 && code <= sfKeyNumpad9)
        append_to_text(base, digits[code - sfKeyNumpad0]);
}

void line_edit_event(line_edit_t *le, sfEvent ev)
{
    char const *base = sfText_getString(le->text);
    char const *end;
    if (ev.type != sfEvtKeyPressed)
        return;
    if (le->has_underscore) {
        remove_last_text(le->text);
        le->has_underscore = 0;
    }
    if (ev.key.code == sfKeyBackspace)
        remove_last_text(le->text);
    else
        append_ev(ev, le->text);
    end = sfText_getString(le->text);
    if (my_strcmp(base, end))
        sfClock_restart(le->underscore);
}
