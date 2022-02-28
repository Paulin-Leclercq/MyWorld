/*
** EPITECH PROJECT, 2021
** nb
** File description:
** nb
*/

#include <stdlib.h>
#include "my.h"

static void show_extrem_min(char **str)
{
    (*str)[my_strlen(*str)] = ('2');
    (*str)[my_strlen(*str)] = ('1');
    (*str)[my_strlen(*str)] = ('4');
    (*str)[my_strlen(*str)] = ('7');
    (*str)[my_strlen(*str)] = ('4');
    (*str)[my_strlen(*str)] = ('8');
    (*str)[my_strlen(*str)] = ('3');
    (*str)[my_strlen(*str)] = ('6');
    (*str)[my_strlen(*str)] = ('4');
    (*str)[my_strlen(*str)] = ('8');
}

static void do_recursion_part(int nb, char **str)
{
    if (nb >= 0 && nb <= 9)
        (*str)[my_strlen(*str)] = (nb + 48);
    else {
        do_recursion_part(nb / 10, str);
        (*str)[my_strlen(*str)] = (nb % 10 + 48);
    }
}

static int nb_len(int nb)
{
    int i = 0;

    do {
        nb /= 10;
        i++;
    } while (nb);
    return i;
}

char *int_to_str_base(int nb)
{
    int neg = (nb < 0) ? (1) : (0);
    char *str = malloc(sizeof(char) * (nb_len(nb) + 2 + neg));

    for (int i = 0; i < nb_len(nb) + neg + 2; str[i] = '\0', i++);
    if (nb < 0) {
        str[0] = ('-');
        nb *= -1;
    }
    if (nb == -2147483648) {
        show_extrem_min(&str);
        return str;
    }
    do_recursion_part(nb, &str);
    return str;
}
