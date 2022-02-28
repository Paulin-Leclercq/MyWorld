/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1-quentin.desmettre
** File description:
** strconcat.c
*/

#include "my.h"
#include <stdlib.h>

static char **init_array(int *lens, int *len, int nb_str, va_list *list)
{
    char **array = malloc(sizeof(char *) * nb_str);

    for (int i = 0; i < nb_str; i++) {
        array[i] = (char *)(va_arg(*list, unsigned long));
        lens[i] = my_strlen(array[i]);
        *len += lens[i];
    }
    return array;
}

static char *concat_array(char **array, int *lens, int nb_str, int len)
{
    char *fin = malloc(sizeof(char) * (len + 1));
    int cur_i = 0;

    for (int i = 0; i < nb_str; i++) {
        my_strcpy(fin + cur_i, array[i]);
        cur_i += lens[i];
    }
    return fin;
}

char *str_concat(int nb_str, ...)
{
    va_list list;
    int len = 0;
    char *fin = NULL;
    char **array;
    int *lens = malloc(sizeof(int) * nb_str);

    va_start(list, nb_str);
    array = init_array(lens, &len, nb_str, &list);
    fin = concat_array(array, lens, nb_str, len);
    va_end(list);
    free(lens);
    free(array);
    return fin;
}
