/*
** EPITECH PROJECT, 2021
** base_trans.c
** File description:
** base_trans
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *exponential(char *t, int y)
{
    char *result = malloc(sizeof(char) * 2);
    char *tmp;

    if (y != 0) {
        result[0] = '1';
        result[1] = '\0';
        for (int i = 0; i < y; i++) {
            tmp = infinmult(result, t);
            free(result);
            result = tmp;
        }
    } else {
        result[0] = '1';
        result[1] = '\0';
    }
    return result;
}

int position(char *str, char cha)
{
    int i = 0;

    for (i; str[i] != cha; i++);
    return i;
}

char *cbase(char *str, char *base, int i, int j)
{
    char *result = malloc(sizeof(char) * 2);
    char *tmp;

    str = my_revstr(str);
    result[0] = '0';
    result[1] = '\0';
    for (int y = 0; y < j; y++) {
        tmp = infinmult(int_to_str_base(position(base, str[y])),
        exponential(int_to_str_base(i), y));
        result = ope(result, tmp);
        free(tmp);
    }
    return result;
}

char *change_base_ten(char *str, char *base)
{
    int i = 0;
    int j = 0;

    for (i; base[i]; i++);
    for (j; str[j]; j++);
    return (cbase(str, base, i, j));
}
