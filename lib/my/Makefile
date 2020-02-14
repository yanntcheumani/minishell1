##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for bsq
##

SRC	=	my_strlowcase.c	\
		my_swap.c	\
		my_putchar.c	\
		my_str_islower.c	\
		my_strncat.c	\
		my_compute_square_root.c	\
		my_put_nbr.c	\
		my_str_isnum.c	\
		my_find_prime_sup.c	\
		my_putstr.c	\
		my_strcat.c	\
		my_str_isprintable.c	\
		my_strncpy.c	\
		my_strcpy.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_strlen.c	\
		my_strupcase.c  \
		linked_list.c	\
		linked_lists.c	\
		my_strcmp.c		\
		get_next_line.c	\
		my_concat.c	\
		my_error.c \
		str_to_word_array.c \
		get_str.c \
		other.c \
		other_two.c \
		my_strstr.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

CPPFLAGS = -I ../../include -Wall -Wextra

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
.PHONY:	clean
