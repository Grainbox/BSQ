/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** tests_my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
}

Test(my_printf, test_my_printf_1, .init = redirect_all_stdout)
{
    my_printf("%s\n", "Hello World");
    cr_assert_stdout_eq_str("Hello World\n");
}

Test(my_printf, test_my_printf_2, .init = redirect_all_stdout)
{
    my_printf("%s\n%i\n", "Hello World", 12);
    cr_assert_stdout_eq_str("Hello World\n12\n");
}

Test(my_printf, test_my_printf_3, .init = redirect_all_stdout)
{
    my_printf("%s\n%i\n%c\n", "Hello World", 12, 'a');
    cr_assert_stdout_eq_str("Hello World\n12\na\n");
}

Test(my_printf, test_my_printf_4, .init = redirect_all_stdout)
{
    my_printf("%S\n%i\n%c\n%s\n", "Hello World", 12, 'a', "Bonjour");
    cr_assert_stdout_eq_str("Hello World\n12\na\nBonjour\n");
}
