/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

void sign(l_spec *spec, int nb)
{
    char charac = (spec->is_zero) ? '0' : ' ';
    spec->width -= (my_len_nbr(nb) > spec->prec) ?
    my_len_nbr(nb) : spec->prec;
    spec->width -= (spec->is_plus || spec->nb_spc > 0) ? 1 : 0;
    (nb >= 0 && spec->is_plus > 0 && charac == '0') ? my_putchar('+') : 0;
    if (spec->is_minus == 0)
        for (int i = 0; i < spec->width; i++, my_putchar(charac));
    (nb >= 0 && spec->is_plus > 0 && charac == ' ') ? my_putchar('+') : 0;
    (nb >= 0 && spec->nb_spc > 0 && spec->is_plus == 0) ? my_putchar(' ') : 0;
    (spec->prec > 0) ? spec->prec -= my_len_nbr(nb) : 0;
    if (spec->prec != 0) {
        for (int i = 0; i < spec->prec; i++)
            my_putchar('0');
    }
    (spec->prec != -1) ? my_put_nbr(nb) : 0;
    if (spec->is_minus == 1)
        for (int i = 0; i < spec->width; i++, my_putchar(charac));
}

void special_cases(l_spec *spec)
{
    if (spec->nb_spc > 0 && spec->spec_char == 'p')
        my_putchar(' ');
}

void str_switch3(l_spec *spec, va_list list_arg)
{
    switch (spec->spec_char) {
        case 'x' :
            (spec->is_hashtag == 1) ? my_putstr("0x") : 0;
            sign_oct_hex(spec, my_putnbr_base(int_to_str_base(va_arg(list_arg
            , int)), "0123456789abcdef", '-'));
            break;
        case 'X' :
            (spec->is_hashtag == 1) ? my_putstr("0X") : 0;
            sign_oct_hex(spec, my_putnbr_base(int_to_str_base(va_arg(list_arg
            , int)), "0123456789ABCDEF", '-'));
            break;
        case 'b' :
            sign_oct_hex(spec, my_putnbr_base(int_to_str_base(va_arg(list_arg
            , int)), "01", '-'));
            break;
        case '%' :
            my_putchar('%');
            break;
    }
}

void str_switch2(l_spec *spec, va_list list_arg)
{
    switch (spec->spec_char) {
        case 'p' :
            width_pointer(spec, long_to_str(va_arg(list_arg
            , unsigned long long)));
            break;
        case 'o' :
            (spec->is_hashtag == 1) ? my_putchar('0') : 0;
            sign_oct_hex(spec, my_putnbr_base(int_to_str_base(va_arg(list_arg
            , int)), "01234567", '-'));
            break;
        case 'u' :
            un_sign(spec, va_arg(list_arg, unsigned int));
            break;
        case 'S' :
            my_non_putstr(va_arg(list_arg, char *));
            break;
        default:
            str_switch3(spec, list_arg);
            break;
    }
}

int str_switch(l_spec *spec, va_list list_arg)
{
    special_cases(spec);
    switch (spec->spec_char) {
        case 'd' :
            sign(spec, va_arg(list_arg, int));
            break;
        case 'i' :
            sign(spec, va_arg(list_arg, int));
            break;
        case 's' :
            width_char_str(spec, va_arg(list_arg, char *));
            break;
        case 'c' :
            width_char_str(spec, my_char_to_str((char) va_arg(list_arg, int)));
            break;
        default:
            str_switch2(spec, list_arg);
            break;
    }
    return 0;
}
