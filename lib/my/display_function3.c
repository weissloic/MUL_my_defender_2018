/*
** EPITECH PROJECT, 2018
** display_function 3
** File description:
** display_function3 for my_printf
*/

#include "../../include/my.h"

void my_put_binary_display(va_list list)
{
    my_put_binary(va_arg(list, int));
}

void my_put_nbr_display(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void my_putchar_display(va_list list)
{
    my_putchar(va_arg(list, int));
}

void my_putstr_display(va_list list)
{
    my_putstr(va_arg(list, char *));
}

void my_unsigned_putnbr_display(va_list list)
{
    my_unsigned_putnbr(va_arg(list, unsigned int));
}