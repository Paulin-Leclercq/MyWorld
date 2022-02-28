##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	my_putchar.c			\
		my_isneg.c				\
		my_put_nbr.c			\
		my_swap.c				\
		my_putstr.c				\
		my_strlen.c				\
		my_getnbr.c				\
		my_sort_int_array.c		\
		my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_is_prime.c			\
		my_find_prime_sup.c		\
		my_strcpy.c				\
		my_strncpy.c			\
		my_revstr.c				\
		my_strstr.c				\
		my_strcmp.c				\
		my_strncmp.c			\
		my_strupcase.c			\
		my_strlowcase.c			\
		my_strcapitalize.c		\
		my_str_isalpha.c		\
		my_str_isnum.c			\
		my_str_islower.c		\
		my_str_isupper.c		\
		my_str_isprintable.c	\
		my_showstr.c			\
		my_showmem.c			\
		my_strcat.c				\
		my_strncat.c			\
		my_show_word_array.c	\
		my_str_to_word_array.c	\
		my_str_replace.c		\
		my_str_move.c			\
		my_count_zero.c			\
		my_strdup.c				\
		my_printf.c				\
		my_is_in_str.c			\
		my_put_unsigned_nbr.c	\
		my_printf_switch.c		\
		my_to_base_ten.c		\
		int_to_str.c			\
		dec_to_base.c			\
		infindiv.c				\
		infinmod.c				\
		infinadd.c				\
		sub.c					\
		sub2.c					\
		my_non_putstr.c			\
		my_is_alphanum.c		\
		my_len_nbr.c			\
		my_memset.c				\
		my_free.c				\
		my_printf_width.c		\
		my_char_to_str.c		\
		long_to_str.c			\
		my_printf_add.c			\
		my_get_long.c

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

MY	=	my.h

all:	$(NAME)

clean:
	rm -f *.o

$(NAME):	$(OBJ)
	cp $(MY) ../../include/
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..

fclean: clean
	rm -f ../$(NAME)
	rm -f $(NAME)

re:	fclean all
