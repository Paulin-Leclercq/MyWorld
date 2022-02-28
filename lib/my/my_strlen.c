/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write a function that displays, one-by-one, the characters of a string.
*/

int my_strlen(char const *str)
{
    int i = *str;
    int count = 0;

    while (i != '\0') {
        count++;
        i = str[count];
    }
    return (count);
}
