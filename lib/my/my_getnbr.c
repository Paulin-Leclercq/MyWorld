/*
** EPITECH PROJECT, 2021
** my_print_comb2.c
** File description:
** Returns a number, sent to the function as a string.
*/

static int is_limit(int temp_nbr, int nbr_add, int neg)
{
    int limit = 2147483647;

    limit -= temp_nbr;
    if (limit <= nbr_add - 1 - neg)
        return (1);
    else
        return (0);
}

static int is_nbr_neg(char const *str, int start_nbr)
{
    int i = *str;
    int count = 0;
    int count_neg = 0;

    while (count < start_nbr) {
        if (i == '-')
            count_neg++;
        if (i < 48 && 57 < i || i != '+' && i != '-')
            return (2);
        count++;
        i = str[count];
    }
    if (count_neg % 2 == 1)
        return (1);
    else
        return (0);
}

static int get_ten(int multi)
{
    int ten = 10;
    if (multi == 1)
        return (1);
    for (int i = 0; i < multi - 2; i++) {
        ten *= 10;
    }
    return (ten);
}

static int write_num(char const *str, int start_nbr, int end_nbr, int count)
{
    int len_nbr;
    int temp_nbr = 0;
    int add = 0;
    int neg = is_nbr_neg(str, start_nbr);

    if (neg == 2)
        return (0);
    if (end_nbr == 0)
        end_nbr = count - 1;
    len_nbr = end_nbr - start_nbr + 1;
    for (int i = 0; i <= len_nbr - 1; i++) {
        add = (str[start_nbr + i] - 48) * get_ten(len_nbr - i);
        if (is_limit(temp_nbr, add, neg) == 1)
            return (0);
        else
            temp_nbr += (str[start_nbr + i] - 48) * get_ten(len_nbr - i);
    }
    if (neg == 1)
        temp_nbr *= -1;
    return (temp_nbr);
}

int my_getnbr(char const *str)
{
    int i = *str;
    int count = 0;
    int is_start_nbr = 0;
    int start_nbr = 0;
    int end_nbr = 0;

    while (i != '\0') {
        if ((48 <= i && i <= 57) && is_start_nbr == 0) {
            is_start_nbr = 1;
            start_nbr = count;
        }
        if ((i < 48 || 57 < i) && is_start_nbr == 1) {
            is_start_nbr = 0;
            end_nbr = count - 1;
            break;
        }
        count++;
        i = str[count];
    }
    return (write_num(str, start_nbr, end_nbr, count));
}
