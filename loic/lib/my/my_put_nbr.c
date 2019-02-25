/*
** EPITECH PROJECT, 2018
** a
** File description:
** a
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int unit;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        unit = unit + 1;
        if (nb = -2147483648){
            my_putchar('2');
            my_put_nbr(147483648);
        }
    }
    if (nb > 9)
        unit = unit + my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return (unit);
}
