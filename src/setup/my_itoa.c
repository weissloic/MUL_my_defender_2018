/*
** EPITECH PROJECT, 2019
** my_itoa.c
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int temp = nb;
    int size = 0;
    char *str;

    while (temp != 0) {
        temp = temp / 10;
        size++;
    }
    str = malloc(sizeof(char) * (size + 1));
    str[size] = 0;
    while (size--) {
        str[size] = nb % 10 + '0';
        nb = nb / 10;
    }
    return (str);
}