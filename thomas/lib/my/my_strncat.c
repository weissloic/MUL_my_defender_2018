/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** Day 07, task 03
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = my_strlen(dest);

    while (src[i] != '\0' && i < nb) {
        dest[j + i] = src[i];
        i++;
    }
    dest[j + i] = '\0';
    return (dest);
}
