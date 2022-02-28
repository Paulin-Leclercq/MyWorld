/*
** EPITECH PROJECT, 2021
** my_put_unsigned_nbr.c
** File description:
** Write a function that displays the unsigned number given as a parameter.
*/

#include "my.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    unsigned int nb_tmp = 0;
    unsigned int nb2 = 0;

    if (nb == 0)
        return (my_putchar('0'));
    if (nb < 0 && nb < 10)
        my_putchar('-');
    nb_tmp = nb % 10;
    nb2 = (nb - nb_tmp) / 10;
    if (nb2 > 0)
        my_put_nbr(nb2);
    my_putchar(nb_tmp + '0');
    return 0;
}
