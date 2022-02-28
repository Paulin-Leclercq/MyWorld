/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write an recursive function that returns nb ^ p.
*/

static int my_prime_find_multi(int nb)
{
    int mid_nbr = nb / 2;
    int start_nbr = 1;
    int multi = 1;

    for (start_nbr = 1; start_nbr <= mid_nbr; start_nbr++) {
        multi = nb / start_nbr;
        if (start_nbr * multi == nb && start_nbr != 1)
            return (1);
    }
    return (0);
}

int my_is_prime(int nb)
{
    if (nb < 2)
        return (0);
    if (my_prime_find_multi(nb) == 0)
        return (1);
    else
        return (0);
}
