/*
** EPITECH PROJECT, 2021
** my_putnbr_base.c
** File description:
** putnbr_base
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static char *reverse(char *number, char const *base)
{
    int i;
    char *j = int_to_str_base(my_strlen(base));
    char *result = malloc(sizeof(char) * 2);

    while (my_strcmp(number, "0") != 0) {
        i = my_getnbr(modbistro(number, j));
        if (i < 0)
            i = -i;
        result[my_strlen(result)] = base[i];
        number = divbistro(number, j);
    }
    free(j);
    return (my_revstr(result));
}

char *my_putnbr_base(char *nbr, char *base, char minus)
{
    char *result = malloc(sizeof(char) * 2);

    result[0] = minus;
    if (nbr[0] == '-' && nbr[1] != '0') {
        result = my_strcat(result, reverse(nbr + 1, base));
        return result;
    }
    if (my_strcmp(nbr, "0") == 0){
        result[0] = base[0];
        return result;
    }
    if (my_strcmp(base, "0123456789") == 0) {
        return nbr;
        return 0;
    }
    return (reverse(nbr, base));
}
