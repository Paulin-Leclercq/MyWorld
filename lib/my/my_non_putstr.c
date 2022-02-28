/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write a function that displays, one-by-one, the characters of a string.
*/

#include "my.h"

int my_non_putstr(char const *str)
{
    int i = *str;
    int count = 0;

    if (i == 0) {
        my_putchar('0');
        return 1;
    }
    while (i != '\0') {
        if (i >= 32 && i <= 126)
            my_putchar(str[count]);
        else {
            my_putchar('\\');
            my_putstr(my_putnbr_base(int_to_str_base(i), "01234567", '-'));
        }
        count++;
        i = str[count];
    }
}
