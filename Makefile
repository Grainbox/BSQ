##
## EPITECH PROJECT, 2021
## BSQ
## File description:
## Makefile
##

SRC	=	src/bsq.c	\
		src/error_handling.c	\
		src/get_nb_rows_cols.c	\
		src/create_buffer.c	\
		src/find_biggest.c	\
		src/find_biggest2.c	\
		src/print_result.c	\
		src/main.c

OBJ = $(SRC:.c=.o)

NAME = bsq

CFLAGS	+= -Wall -Wextra -W -I include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy

clean:
	rm -f $(OBJ)
	rm -f *~
	make clean -C tests

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

re: fclean	all

unit_tests:
	make clean -C tests
	make -C tests

tests_run:
	make run_tests -C tests

.PHONY: clean fclean re
