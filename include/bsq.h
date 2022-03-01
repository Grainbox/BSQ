/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** header
*/

#ifndef BSQ_H_
    #define BSQ_H_

    struct big_square {
        int *square_size;
        int *square_size_bigger;
        int *x;
        int *y;
    };

    int fs_get_number_from_first_line(int fd, int *nb_rows, int *nb_cols);

    int error_handle(int argc);

    int check_read_result(int returned);

    char **create_buffer(char *filepath, int nb_rows, int nb_cols);

    int *wich_bigger(char **map, int nb_rows, int nb_cols, int *square_size);

    void print_square(char **buffer, int x, int y, int size);

    void print_result(char **buffer, int nb_rows);

    int bsq(int argc, char **argv);

    struct big_square check_square(struct big_square square, int i, int j);

#endif /* !BSQ_H_ */
