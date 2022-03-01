/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** bsq
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"

static void free_memory(int fd, char **buffer, int nb_rows)
{
    close(fd);
    for (int i = 0; i < nb_rows; i++)
        free(buffer[i]);
    free(buffer);
}

static int open_file(char *filepath, int *fd)
{
    *fd = open(filepath, O_RDONLY);

    if (*fd == -1) {
        my_puterror("Failure\n");
        return 84;
    }

    return 0;
}

int bsq(int argc, char **argv)
{
    char **buffer;
    int fd = 0;
    int nb_rows = 0;
    int nb_cols = 0;
    int error = error_handle(argc);
    if (error == 84)
        return error;
    int square_size = 0;
    int *xy;
    for (error = error; error == 0; error++) {
        error = open_file(argv[1], &fd);
        error = fs_get_number_from_first_line(fd, &nb_rows, &nb_cols);
        buffer = create_buffer(argv[1], nb_rows, nb_cols);
        xy = wich_bigger(buffer, nb_rows, nb_cols, &square_size);
        print_square(buffer, xy[0], xy[1], square_size);
        print_result(buffer, nb_rows);
    }
    free_memory(fd, buffer, nb_rows);
    return error - 1;
}
