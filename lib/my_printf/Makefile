##
## EPITECH PROJECT, 2019
## day10
## File description:
## task01
##

SRC	=	my_printf_s.c   \
		my_printf.c \
		lib.c       \
		my_printf_type.c    \
		my_printf_convert.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	printf.a

all: 	$(NAME)

############create lybrairies ###################
$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

############clean files tmp and *.o##############
clean:		$(OBJ)
	rm -f $(OBJ)

############clean *.o and $(NAME)################
fclean:	clean
	rm -f $(NAME)
	find . -name "*[#|~]" -delete  -o -name "[#]*" -delete

re: all clean

auteur:
	echo $(USER) > auteur
