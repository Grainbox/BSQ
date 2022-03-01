##
## EPITECH PROJECT, 2021
## BSQ
## File description:
## makefile_tests
##

SRC	=	BSQ_tests.c

SRC2	=	../src/bsq.c	\
			../src/create_buffer.c	\
			../src/error_handling.c	\
			../src/find_biggest.c		\
			../src/find_biggest2.c		\
			../src/get_nb_rows_cols.c	\
			../src/print_result.c

LIB	=	-L ../lib/my -lmy

HEADER	=	-I ../include

Criterion	=	-lcriterion --coverage

all:
	gcc -o unit_tests $(SRC) $(SRC2) $(HEADER) $(LIB) $(Criterion) -g

run_tests:
	./unit_tests

clean:
	rm -f *.gcno	\
    rm -f *.gcda	\
    rm -f *~		\
    rm -f unit_tests