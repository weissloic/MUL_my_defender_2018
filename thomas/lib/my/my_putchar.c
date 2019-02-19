/*
** EPITECH PROJECT, 2018
** a
** File description:
** a
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
