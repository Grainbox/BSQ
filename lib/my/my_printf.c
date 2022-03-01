/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>

void print_arg(va_list args, char *str, int *i)
{
    if (str[*i] == '%')
        ++*i;
    if (str[*i] == 'd' && str[*i - 1] == '%') {
        my_put_nbr(va_arg(args, int));
        ++*i;
    }
    if (str[*i] == 's' && str[*i - 1] == '%') {
        my_putstr(va_arg(args, char *));
        ++*i;
    }
    if (str[*i] == 'c' && str[*i - 1] == '%') {
        my_putchar(va_arg(args, int));
        ++*i;
    }
}

void my_printf(char *str, ...)
{
    va_list args;
    int i = 0;
    int size = my_strlen(str);

    va_start(args, str);
    for (i = 0; str[i] != '\0'; i++) {
        print_arg(args, str, &i);
        my_putchar(str[i]);
    }
    va_end(args);
}