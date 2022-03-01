/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** find_biggest
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "bsq.h"

static int *find_biggest_xy(char **map, int row, int col, int nb_rows)
{
    int x = 0;
    int y = 0;
    int square_x = 0;
    int square_y = 0;

    for (x = col; map[row][x] != '\0'; x++) {
        if (map[row][x] == 'o')
            break;
        square_x++;
    }
    for (y = row; y < nb_rows; y++) {
        if (map[y][col] == 'o')
            break;
        square_y++;
    }

    int *array = malloc(sizeof(int) * 2);
    array[0] = square_x;
    array[1] = square_y;
    return array;
}

static int is_square_of_size(char **map , int row , int col , int square_size)
{
    int i = 0;
    int j = 0;

    for (j = row; j < (row + square_size); j++) {
        for (i = col; i < (col + square_size); i++) {
            if (map[j][i] != '.')
                return 0;
        }
    }

    return 1;
}

static int return_process(int square_size)
{
    if (square_size == -1)
        square_size += 2;
    else
        square_size++;

    return square_size;
}

static int find_biggest_square(char **map , int nb_rows, int row, int col)
{
    int *arr_bigger = find_biggest_xy(map, row, col, nb_rows);
    int square_x = arr_bigger[0];
    int square_y = arr_bigger[1];
    int square = 0;

    free(arr_bigger);
    if (square_x >= square_y) {
        while (square != 1) {
            square = is_square_of_size(map, row, col, square_y);
            square_y--;
        }
        return return_process(square_y);
    } else {
        while (square != 1) {
            square = is_square_of_size(map, row, col, square_x);
            square_x--;
        }
        return return_process(square_x);
    }
    return 0;
}

int *wich_bigger(char **map, int nb_rows, int nb_cols, int *biggest_size)
{
    int square_size = 0;
    int square_size_bigg = 0;
    int x = 0;
    int y = 0;
    struct big_square square = { &square_size, &square_size_bigg, &x, &y };
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            square_size = find_biggest_square(map, nb_rows, i, j);
            square = check_square(square, i, j);
        }
    }
    int *xy_arr = malloc(sizeof(int) * 2);
    xy_arr[0] = x;
    xy_arr[1] = y;
    *biggest_size = square_size_bigg;
    return xy_arr;
}
