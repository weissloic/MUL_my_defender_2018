/*
** EPITECH PROJECT, 2018
** my is prime
** File description:
** Day 05 task 06
*/

int my_is_prime(int nb)
{
    int i = 0;
    int j = 0;

    while (i <= nb) {
        i = i + 1;
        if (nb % i == 0)
            j = j + 1;
    }
    if (j == 2)
        return (1);
    else
        return (0);
}
