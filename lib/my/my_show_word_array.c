/*
** EPITECH PROJECT, 2018
** my show word array
** File description:
** Day 08 task 03
*/

#include "../../include/my.h"
#include <stdlib.h>

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
