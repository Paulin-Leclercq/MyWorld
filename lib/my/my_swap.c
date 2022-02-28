/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write a function that swaps the content of two integers.
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
