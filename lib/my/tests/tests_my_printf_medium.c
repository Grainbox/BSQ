/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** tests_my_printf_medium
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void);

Test(my_printf, test_my_printf_octal_1, .init = redirect_all_stdout)
{
    my_printf("%o", 8);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf, test_my_printf_octal_2, .init = redirect_all_stdout)
{
    my_printf("%o%o", 123, 188);
    cr_assert_stdout_eq_str("173274");
}

Test(my_printf, test_my_printf_octal_3, .init = redirect_all_stdout)
{
    my_printf("%o%o abcd %o", 123, 188, 2);
    cr_assert_stdout_eq_str("173274 abcd 2");
}

Test(my_printf, test_my_printf_hexa_1, .init = redirect_all_stdout)
{
    my_printf("%x%X", 188, 12);
    cr_assert_stdout_eq_str("bcC");
}

Test(my_printf, test_my_printf_hexa_2, .init = redirect_all_stdout)
{
    my_printf("%X%X", 230, 122);
    cr_assert_stdout_eq_str("E67A");
}
