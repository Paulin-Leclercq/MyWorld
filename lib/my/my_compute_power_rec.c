/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write an recursive function that returns nb ^ p.
*/

static int max_multi(int result, int nb)
{
    int limite = 2147483647;
    int nb_max = limite / nb;

    if (result > nb_max)
        return (1);
    else
        return (0);
}

int my_compute_power_rec(int nb, int p)
{
    int result = 1;
    int neg = 1;
    if (p == 0 || p == 1 || p < 0) {
        if (p == 1)
            return (nb);
        if (p < 0)
            return (0);
        return (1);
    }
    if (nb < 0) {
        if (p % 2 == 1)
            neg = -1;
        nb *= -1;
    }
    result = my_compute_power_rec(nb, p - 1);
    if (max_multi(result, nb) == 0)
        result *= nb;
    else
        return (0);
    return (result * neg);
}
