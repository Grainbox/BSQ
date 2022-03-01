/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** get_nb_rows
*/

/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** 1_step6
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "bsq.h"

static void find_first_line(char *buffer)
{
    int i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            break;
        i++;
    }
    buffer[i] = '\0';
}

static int data_process(char *buffer)
{
    int i = 0;

    if (buffer[0] == '\0')
        return -1;
    while (buffer[i] != '\0') {
        if (buffer[i] < '0' || buffer[i] > '9')
            return 84;
        i++;
    }
    return 0;
}

static int char_to_int(char *str)
{
    int i = 0;
    int result = 0;
    int mult = 1;
    int neg = 0;
    while (str[i] != '\0')
        i++;
    i--;
    while (i != -1) {
        if (str[i] == '-') {
            neg++;
            break;
        }
        result += (str[i] - '0') * mult;
        mult *= 10;
        i--;
    }
    if (neg > 0)
        result *= -1;
    return result;
}

static int get_nb_cols(char *buffer)
{
    int i = 0;
    int count = 0;

    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            break;
    }
    for (i = i + 1; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            break;
        count++;
    }

    return count;
}

int fs_get_number_from_first_line(int fd, int *nb_rows, int *nb_cols)
{
    char buffer[100000];
    int returned = 0;
    int error = 0;
    returned = read(fd, buffer, 100000);
    if (check_read_result(returned) == 84)
        return 84;
    find_first_line(buffer);
    error = data_process(buffer);
    if (error == 0 && returned != 0) {
        *nb_rows = char_to_int(buffer);
    } else {
        my_puterror("NOT STRICTLY POSITIVE NUMBER\n");
        return 84;
    }
    *nb_cols = get_nb_cols(buffer);

    return error;
}
