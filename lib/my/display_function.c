/*
** EPITECH PROJECT, 2018
** display_function.c
** File description:
** useful functions for my_printf
*/

#include "../../include/my.h"

int my_put_binary(int nb)
{
    int unit = 0;
    char *base = "01";
    int len = my_strlen(base);

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        unit = unit + 1;
    }
    if (nb > len)
        unit = unit + my_put_binary(nb/len);
    my_putchar(base[nb % len]);
    return (unit);
}

long my_put_pointer(long nb)
{
    long unit = 0;
    char *base = "0123456789abcdef";
    int len = my_strlen(base);

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        unit = unit + 1;
    }
    if (nb > len)
        unit = unit + my_put_pointer(nb/len);
    my_putchar(base[nb % len]);
    return (unit);
}

int my_put_hexa(int nb)
{
    int unit = 0;
    char *base = "0123456789abcdef";
    int len = my_strlen(base);

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        unit = unit + 1;
    }
    if (nb > len)
        unit = unit + my_put_hexa(nb/len);
    my_putchar(base[nb % len]);
    return (unit);
}

int my_put_hexa_up(int nb)
{
    int unit = 0;
    char *base = "0123456789ABCDEF";
    int len = my_strlen(base);

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        unit = unit + 1;
    }
    if (nb > len)
        unit = unit + my_put_hexa_up(nb/len);
    my_putchar(base[nb % len]);
    return (unit);
}

/*int my_put_nbr(int nb)
{
    int unit = 0;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        unit = unit + 1;
        if (nb == -2147483648){
            my_putchar('2');
            my_put_nbr(147483648);
        }
    }
    if (nb > 9)
        unit = unit + my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return (unit);
}*/