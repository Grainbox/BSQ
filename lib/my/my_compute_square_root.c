/*
** EPITECH PROJECT, 2021
** My_Compute_Square_Root
** File description:
** racine carré
*/

int my_compute_square_root(int nb)
{
    int i = 0;
    int div = 1;
    if (nb > 0) {
        if (nb == 1) {
            return (1);
        }
        while (nb != 1) {
            nb = nb / 2;
            i++;
        }
        return (i);
    }
    else {
        return (0);
    }
}
