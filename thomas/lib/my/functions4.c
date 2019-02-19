/*
** EPITECH PROJECT, 2018
** function4.c
** File description:
** more functions for my_printf
*/

#include "../../include/my.h"

unsigned int my_unsigned_putnbr(unsigned int nb)
{
    unsigned int unit = 0;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        unit = unit + 1;
    }
    if (nb > 9)
        unit = unit + my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return (unit);
}

unsigned char *my_full_putstr(unsigned char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        my_putchar(s[i]);
        if (s[i] >= 127) {
            my_putchar('\\');
            my_put_octal(s[i]);
        }
        if (s[i] < 32) {
            my_putchar('\\');
            my_putchar('0');
            my_put_octal(s[i]);
        }
    }
    return (s);
}

void my_full_putstr_display(va_list list)
{
    my_full_putstr(va_arg(list, unsigned char *));
}
