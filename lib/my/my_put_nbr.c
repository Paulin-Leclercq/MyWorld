/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write a function that displays the number given as a parameter.
*/

#include "my.h"

int abs(int nb)
{
    if (nb < 0)
        nb = -nb;
    return nb;
}

int my_put_nbr(int nb)
{
    int nb_tmp = 0;
    int nb2 = 0;

    if (nb == 0)
        return (my_putchar('0'));
    if (nb < 0 && abs(nb) < 10)
        my_putchar('-');
    nb_tmp = nb % 10;
    nb2 = (nb - nb_tmp) / 10;
    if (abs(nb2) > 0)
        my_put_nbr(nb2);
    my_putchar(abs(nb_tmp) + '0');
    return 0;
}
