/*
** EPITECH PROJECT, 2018
** my compute power rec
** File description:
** day 05  task 04
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (p != 1)
        nb = nb * my_compute_power_rec(nb, (p-1));
    if (nb > 2147483647)
        return (0);
    return (nb);
}
