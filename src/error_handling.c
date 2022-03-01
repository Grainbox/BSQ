/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** error_handling
*/

#include "my.h"

int error_handle(int argc)
{
    if (argc == 1 || argc > 2) {
        my_puterror("Wrong argument\n");
        return 84;
    }
    return 0;
}

int check_read_result(int returned)
{
    if (returned == -1) {
        my_puterror("read_failed\n");
        return 84;
    }
    if (returned == 0) {
        my_puterror("read has nothing more to read\n");
        return 84;
    }
    return 0;
}
