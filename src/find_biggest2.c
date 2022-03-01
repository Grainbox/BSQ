/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-tom.daniel
** File description:
** find_biggest2
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "bsq.h"

struct big_square check_square(struct big_square square, int i, int j)
{
    if (*square.square_size > *square.square_size_bigger) {
        *square.square_size_bigger = *square.square_size;
        *square.x = j;
        *square.y = i;
    }
    return square;
}
