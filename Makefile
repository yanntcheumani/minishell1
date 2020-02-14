##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Makefile
##

NAME	=	mysh

SRC	=	src/exec_command.c	\
		src/env_builtins.c 	\
		src/main.c	\
		src/shell.c	\
		src/wave.c	\
		src/path.c	\
		src/my_cd.c

OBJ	=	$(SRC:.c=.o)

UT_NAME	=	unit_tests

all:	$(NAME)

CPPFLAGS = -I include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm lib/my/libmy.a
	rm lib/my_printf/printf.a

debug: CFLAGS += -g3
debug:	$(OBJ)
	make -C lib/my
	make -C lib/my_printf
	gcc -o $(NAME) $(OBJ) $(CFLAGS) lib/my_printf/printf.a lib/my/libmy.a

tests_run:	$(UT_OBJ)
	make -C lib/my
	make -C lib/my clean
	gcc --coverage $(CFLAGS) -o $(NAME) $(OBJ) -L./lib/my -lmy -lcriterion
	./unit_tests

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/my_printf
	make clean -C lib/my
	make clean -C lib/my_printf
	gcc -o $(NAME) $(OBJ) ./lib/my_printf/printf.a ./lib/my/libmy.a
	make clean

re: fclean all
