/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** Day 07 , task 02
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen(dest);

    while (src[i] != '\0') {
        dest[j + i] = src[i];
        i++;
    }
    dest[j + i] = '\0';
    return (dest);
}
