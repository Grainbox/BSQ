/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** create_buffer
*/

#include "my.h"
#include "bsq.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void skip_first_line(int *i, char *buffer)
{
    while (buffer[*i] != '\0') {
        if (buffer[*i] == '\n') {
            ++*i;
            break;
        }
        ++*i;
    }
}

static char *load_line_in_arr(char *buffer, char **xy_buffer, int y)
{
    int i = 0;
    int j = 0;
    int y_searched = 0;
    skip_first_line(&i, buffer);
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n' && y_searched == y)
            break;
        if (buffer[i] == '\n') {
            y_searched++;
            i++;
        }
        if (y_searched == y) {
            xy_buffer[y][j] = buffer[i];
            j++;
        }
        i++;
    }
    xy_buffer[y][j] = '\0';
    return xy_buffer[y];
}

static void fill_buffer(char **xy_buffer, char *buffer, int nb_rows)
{
    int y = 0;

    for (y = 0; y < nb_rows; y++)
        xy_buffer[y] = load_line_in_arr(buffer, xy_buffer, y);
}

static char ** create_2d_array(char *buffer, int nb_rows , int nb_cols)
{
    char **arr = malloc(sizeof(char *) * nb_rows);
    int i = 0;

    for (i = 0; i < nb_rows; i++)
        arr[i] = malloc(nb_cols + 1);
    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            break;
    }
    fill_buffer(arr, buffer, nb_rows);
    free(buffer);
    return arr;
}

char **create_buffer(char *filepath, int nb_rows, int nb_cols)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    buffer = malloc(sizeof(char) * (nb_rows * nb_cols + (nb_cols * nb_rows)));
    int fc = read(fd, buffer, (nb_rows * nb_cols + (nb_cols * nb_rows)));
    buffer[fc] = '\0';
    close(fd);
    return create_2d_array(buffer, nb_rows, nb_cols);
}
