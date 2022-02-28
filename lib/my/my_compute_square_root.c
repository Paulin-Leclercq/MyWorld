/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Returns the square root of the parameter.
*/

int my_compute_square_root(int nb)
{
    int mid_nbr = nb / 2;
    int start_nbr = 1;

    if (nb == 1 || nb == 0)
        return (nb);
    for (start_nbr = 1; start_nbr <= mid_nbr; start_nbr++) {
        if (start_nbr * start_nbr == nb && start_nbr != 1)
            return (start_nbr);
    }
    return (0);
}
