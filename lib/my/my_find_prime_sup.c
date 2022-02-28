/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write a function that returns the smallest prime number greater than nb.
*/

static int my_test_prime_find_multi(int nb)
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

static int my_test_prime(int nb)
{
    if (nb < 2)
        return (0);
    if (my_test_prime_find_multi(nb) == 0)
        return (1);
    else
        return (0);
}

int my_find_prime_sup(int nb)
{
    int prime_found = 0;

    while (prime_found == 0) {
        if (my_test_prime(nb) == 1)
            prime_found = 1;
        nb++;
    }
    return (nb - 1);
}
