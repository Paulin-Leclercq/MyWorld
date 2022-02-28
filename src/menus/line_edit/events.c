/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** events.c
*/

#include "menus.h"
#include "my.h"

static const char *codes[] = {
    "A", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
    "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
};

static const char *digits[] = {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

char *switch_ev(sfEvent ev, char const *base)
{
    int code = ev.key.code;

    if (code <= sfKeyZ && code >= sfKeyA)
        return str_concat(2, base, codes[code]);
    if (code == sfKeyNum8 && !ev.key.shift)
        return str_concat(2, base, "_");
    if (code == sfKeyHyphen)
        return str_concat(2, base, ev.key.shift ? "6" : "-");
    if (code == sfKeyQuote && ev.key.shift)
        return str_concat(2, base, "4");
    if (ev.key.shift && code >= sfKeyNum0 && code <= sfKeyNum9)
        return str_concat(2, base, digits[code - sfKeyNum0]);
    if (code >= sfKeyNumpad0 && code <= sfKeyNumpad9)
        return str_concat(2, base, digits[code - sfKeyNumpad0]);
    return my_strdup(base);
}

void line_edit_event(line_edit_t *le, sfEvent ev)
{
    char const *str = sfText_getString(le->text);
    char *new;

    if (ev.type != sfEvtKeyPressed)
        return;
    if (ev.key.code == sfKeyBackspace) {
        new = my_strdup(str);
        new[my_strlen(new) - 1] = 0;
    } else
        new = switch_ev(ev, str);
    sfText_setString(le->text, new);
    free(new);
}
