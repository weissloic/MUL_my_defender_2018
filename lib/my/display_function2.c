/*
** EPITECH PROJECT, 2018
** display_fucntion2.c
** File description:
** more functions for my_printf
*/

#include "../../include/my.h"

int my_put_octal(int nb)
{
    int unit = 0;
    char *base = "01234567";
    int len = my_strlen(base);

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        unit = unit + 1;
    }
    if (nb > len)
        unit = unit + my_put_octal(nb/len);
    my_putchar(base[nb % len]);
    return (unit);
}

void my_put_hexa_display(va_list list)
{
    my_put_hexa(va_arg(list, int));
}

void my_put_octal_display(va_list list)
{
    my_put_octal(va_arg(list, int));
}

void my_put_hexa_up_display(va_list list)
{
    my_put_hexa_up(va_arg(list, int));
}

void my_put_pointer_display(va_list list)
{
    my_putstr("0x");
    my_put_pointer(va_arg(list, long));
}