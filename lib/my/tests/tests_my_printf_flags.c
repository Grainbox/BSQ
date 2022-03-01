/*
** EPITECH PROJECT, 2021
** B-PSU-100-REN-1-1-myprintf-tom.daniel
** File description:
** tests_my_printf_flags
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void);

Test(my_printf, test_my_printf_ashtag_octal_1, .init = redirect_all_stdout)
{
    my_printf("%#o", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, test_my_printf_ashtag_octal_2, .init = redirect_all_stdout)
{
    my_printf("%#o", 8);
    cr_assert_stdout_eq_str("010");
}

Test(my_printf, test_my_printf_ashtag_octal_3, .init = redirect_all_stdout)
{
    my_printf("%#o%#o", 1028, 21);
    cr_assert_stdout_eq_str("02004025");
}

Test(my_printf, test_my_printf_ashtag_hexa_1, .init = redirect_all_stdout)
{
    my_printf("%#x", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, test_my_printf_ashtag_hexa_2, .init = redirect_all_stdout)
{
    my_printf("%#x", 16);
    cr_assert_stdout_eq_str("0x10");
}
