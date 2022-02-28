/*
** EPITECH PROJECT, 2021
** my_len_nbr.c
** File description:
** my_len_nbr
*/

#include "my.h"

int my_len_nbr(int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        nb = -nb;
        len++;
    }
    for (; nb > 0; len++)
        nb /= 10;
    return len;
}
