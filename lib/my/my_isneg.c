/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** Write a function that displays if it's positive or null.
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar(78);
    else
        my_putchar(80);
    return (0);
}
