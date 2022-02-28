/*
** EPITECH PROJECT, 2021
** sub2.c
** File description:
** sub2
*/

void carry_neg(char **result, int size)
{
    if ((*result)[size] < 0) {
        (*result)[size] += 10;
        (*result)[size - 1] = -1;
    }
    (*result)[size] += '0';
}

void add_end_nbr_neg(int i, char **result, int size, char *tab)
{
    for (; i != 0; i--, size--) {
        (*result)[size] += tab[i - 1] - '0';
        carry_neg(result, size);
    }
}
