/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** print_result
*/

#include "my.h"

void print_result(char **buffer, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++)
        my_printf("%s\n", buffer[i]);
}

void print_square(char **buffer, int x, int y, int size)
{
    int i = y;
    int j = x;

    for (y = i; y < (size + i); y++) {
        if (size == 1 && buffer[y][x] == 'o')
            break;
        for (x = j; x < (size + j); x++) {
            buffer[y][x] = 'x';
        }
    }
}
