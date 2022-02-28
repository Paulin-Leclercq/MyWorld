/*
** EPITECH PROJECT, 2021
** my_count_zero.c
** File description:
** my_count_zero
*/

int count_zero(char *nb)
{
    int i = 0;

    for (; nb[i] != '\0' && (nb[i] == '0' || nb[i] == '-'); i++);
    return (i);
}
