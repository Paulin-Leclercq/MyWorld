/*
** EPITECH PROJECT, 2021
** nb
** File description:
** nb
*/

#include <stdlib.h>
#include "my.h"

static void do_recursion_part(unsigned long long nb, char **str)
{
    if (nb >= 0 && nb <= 9)
        (*str)[my_strlen(*str)] = (nb + 48);
    else {
        do_recursion_part(nb / 10, str);
        (*str)[my_strlen(*str)] = (nb % 10 + 48);
    }
}

static unsigned long long nb_len(unsigned long long nb)
{
    unsigned long long i = 0;

    do {
        nb /= 10;
        i++;
    } while (nb);
    return i;
}

char *long_to_str(unsigned long long nb)
{
    char *str = malloc(sizeof(char) * (nb_len(nb) + 2));

    for (int i = 0; i < nb_len(nb) + 2; str[i] = '\0', i++);
    do_recursion_part(nb, &str);
    return str;
}
