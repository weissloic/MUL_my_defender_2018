/*
** EPITECH PROJECT, 2018
** my find prime sup
** File description:
** Day 05 task 07
*/

int prime_test(int nb)
{
    int j = 0;
    int k = 0;

    while (j <= nb) {
        j = j + 1;
        if (nb % j == 0)
            k = k + 1;
    }
    if (k == 2)
        return (1);
    else
        return (0);
}

int my_find_prime_sup(int nb)
{
    int i = nb;

    if (prime_test(nb) != 1) {
        while (prime_test(i) != 1) {
            i = i + 1;
        }
        return (i);
    }
    else if (prime_test(nb) == 1) {
        return (nb);
    }
}
