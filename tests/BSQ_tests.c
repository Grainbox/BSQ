/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** BSQ_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(bsq, final_return1, .init = redirect_all_stdout)
{
        int argc = 2;
        char fp[] = "../mouli_maps/intermediate_map_100_100";
        char fp_solved[] = "../map_sol/intermediate_map_100_100";
        char *argv[2] = {"./bsq", fp};
        int fd = open(fp_solved, O_RDONLY);
        char buffer[10101];
        int fc = read(fd, buffer, 10101);
        buffer[fc] = '\0';
        int returned = bsq(argc, argv);
        cr_assert_stdout_eq_str(buffer);
        cr_assert_eq(returned, 0);
}

Test(bsq, final_return2, .init = redirect_all_stdout)
{
        int argc = 2;
        char fp[] = "../mouli_maps/intermediate_map_34_137_empty";
        char fp_sol[] = "../map_sol/intermediate_map_34_137_empty";
        char *argv[2] = {"./bsq", fp};
        int fd = open(fp_sol, O_RDONLY);
        char buffer[10101];
        int fc = read(fd, buffer, 10101);
        buffer[fc] = '\0';
        int returned = bsq(argc, argv);
        cr_assert_stdout_eq_str(buffer);
        cr_assert_eq(returned, 0);
}

Test(bsq, final_return3, .init = redirect_all_stdout)
{
        int argc = 2;
        char f[] = "../mouli_maps/intermediate_map_34_137_with_obstacles_75pc";
        char f_sol[] = "../map_sol/intermediate_map_34_137_with_obstacles";
        char *argv[2] = {"./bsq", f};
        int fd = open(f_sol, O_RDONLY);
        char buffer[10101];
        int fc = read(fd, buffer, 10101);
        buffer[fc] = '\0';
        int returned = bsq(argc, argv);
        cr_assert_stdout_eq_str(buffer);
        cr_assert_eq(returned, 0);
}

Test(bsq, final_return4, .init = redirect_all_stdout)
{
        int argc = 2;
        char fp[] = "../mouli_maps/intermediate_map_one_filled_box";
        char fp_sol[] = "../map_sol/intermediate_map_one_filled_box";
        char *argv[2] = {"./bsq", fp};
        int fd = open(fp_sol, O_RDONLY);
        char *buffer = malloc(1000000);
        int fc = read(fd, buffer, 1000000);
        buffer[fc] = '\0';
        int returned = bsq(argc, argv);
        cr_assert_stdout_eq_str(buffer);
        cr_assert_eq(returned, 0);
}