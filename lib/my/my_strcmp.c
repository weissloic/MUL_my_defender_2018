/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** day 07 task 05
*/

#include "../../include/my.h"

int comparator(char const *s1, char const *s2, int j)
{
    if (s1[j] > s2[j])
        return (1);
    else if (s1[j] < s2[j])
        return (-1);
    else
        return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (comparator(s1, s2, i));
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-1);
    else if (s1[i] != '\0' && s2[i] == '\0')
        return (1);
    return (0);
}
