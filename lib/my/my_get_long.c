/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my_getnbr
*/

long long int str_to_long(char const *str)
{
    long long int nb = 0;
    int is_neg = str[0] == '-';

    for (int i = is_neg; str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return is_neg ? -nb : nb;
}
