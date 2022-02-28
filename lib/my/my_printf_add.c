/*
** EPITECH PROJECT, 2021
** my_printf_add.c
** File description:
** my_printf_add
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int add_length(char *str, int start, l_spec *spec)
{
    int len = start;
    char *length = malloc(sizeof(char));

    length = my_strncat(length, str + start, 1);
    if (is_in_str(length[0], "lh") == 1 && str[start + 1] == length[0])
        length = my_strncat(length, str + start + 1, 1);
    if (spec->length == 0)
        spec->length = length;
    return my_strlen(length) - 1;
}

int add_prec(char *str, int start, l_spec *spec)
{
    int len = start;
    char *prec = malloc(sizeof(char));

    for (; is_in_str(str[len], "0123456789") == 1 && str[len] != '\0'; len++)
        prec = my_strncat(prec, str + len, 1);
    if (spec->prec == 0)
        if (prec == 0 || my_getnbr(prec) == 0)
            spec->prec = -1;
        else
            spec->prec = my_getnbr(prec);
    return len - start;
}

void add_flags(char *str, int start, l_spec *spec)
{
    if (str[start] == '+') {
        spec->is_plus = 1;
        spec->nb_spc = 0;
    }
    if (str[start] == ' ' && spec->is_plus == 0)
        spec->nb_spc = 1;
    if (str[start] == '#')
        spec->is_hashtag = 1;
    if (str[start] == '-') {
        spec->is_minus = 1;
        spec->is_zero = 0;
    }
    if (str[start] == '0' && spec->is_minus == 0)
        spec->is_zero = 1;
}
