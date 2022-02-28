/*
** EPITECH PROJECT, 2021
** my_printf_width.c
** File description:
** my_printf_width
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int add_width(char *str, int start, l_spec *spec)
{
    int len = start;
    char *width = malloc(sizeof(char));

    for (; is_in_str(str[len], "0123456789") == 1 && str[len] != '\0'; len++)
        width = my_strncat(width, str + len, 1);
    if (spec->width == 0)
        spec->width = my_getnbr(width);
    return len - start - 1;
}

void sign_oct_hex(l_spec *spec, char *nb)
{
    char charac = (spec->is_zero) ? '0' : ' ';
    spec->width -= (my_strlen(nb) > spec->prec) ?
    my_strlen(nb) - 1 : spec->prec;
    spec->width -= (spec->is_plus || spec->nb_spc > 0) ? 1 : 0;
    if (spec->is_minus == 0)
        for (int i = 0; i < spec->width; i++, my_putchar(charac));
    spec->prec -= my_strlen(nb);
    if (spec->prec != 0) {
        for (int i = 0; i < spec->prec; i++)
            my_putchar('0');
    }
    my_putstr(nb);
    if (spec->is_minus == 1)
        for (int i = 0; i < spec->width; i++, my_putchar(charac));
}

void un_sign(l_spec *spec, unsigned int nb)
{
    char charac = (spec->is_zero) ? '0' : ' ';
    spec->width -= (my_len_nbr(nb) > spec->prec) ?
    my_len_nbr(nb) - 1 : spec->prec;
    spec->width -= (spec->is_plus || spec->nb_spc > 0) ? 1 : 0;
    if (spec->is_minus == 0)
        for (int i = 0; i < spec->width; i++, my_putchar(charac));
    (nb >= 0 && spec->nb_spc > 0 && spec->is_plus == 0) ? my_putchar(' ') : 0;
    (spec->prec > 0) ? spec->prec -= my_len_nbr(nb) : 0;
    if (spec->prec != 0) {
        for (int i = 0; i < spec->prec; i++)
            my_putchar('0');
    }
    (spec->prec != -1) ? my_put_unsigned_nbr(nb) : 0;
    if (spec->is_minus == 1)
        for (int i = 0; i < spec->width; i++, my_putchar(charac));
}

void width_char_str(l_spec *spec, char *str)
{
    if (spec->prec == 0)
        spec->prec = my_strlen(str);
    spec->width -= (spec->prec < my_strlen(str)) ? spec->prec : my_strlen(str);
    if (spec->is_minus == 0)
        for (int i = 0; i < spec->width; i++, my_putchar(' '));
    for (int i = 0; i < spec->prec && str[i] != '\0'; i++)
        my_putchar(str[i]);
    if (spec->is_minus == 1)
        for (int i = 0; i < spec->width; i++, my_putchar(' '));
}

void width_pointer(l_spec *spec, char *str)
{
    int i = 0;

    str = my_putnbr_base(str, "0123456789ABCDEF", '-');
    (spec->is_plus) ? my_putstr("+0x") : my_putstr("0x");
    spec->prec = (spec->prec > spec->prec) ? spec->prec : spec->prec;
    if (spec->prec > my_strlen(str))
        for (; i < spec->prec - my_strlen(str); i++)
            my_putchar('0');
    my_putstr(str);
    spec->width = spec->width - my_strlen(str) - spec->is_plus - i - 2;
    if (spec->width > 0)
        for (int j = 0; j < spec->width; j++)
            my_putchar(' ');
}
