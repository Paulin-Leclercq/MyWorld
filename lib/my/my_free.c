/*
** EPITECH PROJECT, 2021
** my_free.c
** File description:
** my_free
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void free_itable(int **table)
{
    for (int i = 0; table[i] != 0; i++)
        free(table[i]);
    free(table);
}

void free_ctable(char **table)
{
    for (int i = 0; table[i] != 0; i++)
        free(table[i]);
    free(table);
}

void my_free(char *to_free, ...)
{
    va_list list_arg;

    va_start(list_arg, to_free);
    for (int i = 0; i < my_getnbr(to_free) - 1; i++) {
        if (to_free[i + 1] == 's')
            free(va_arg(list_arg, char *));
        if (to_free[i + 1] == 'S')
            free_ctable(va_arg(list_arg, char **));
        if (to_free[i + 1] == 'i')
            free(va_arg(list_arg, int *));
        if (to_free[i + 1] == 'I')
            free_itable(va_arg(list_arg, int **));
    }
    va_end(list_arg);
}
