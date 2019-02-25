/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** main file for my_printf
*/

#include "../../include/my.h"

int my_printf(char *s, ...)
{
    va_list list;

    va_start(list, s);
    print_func(s, list);
    va_end(list);
}

void print_func(char *s, va_list list)
{
    char tab[11] = {'d', 'i', 's', 'c', 'p', 'x', 'X', 'b', 'o', 'u', 'S'};
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            s++;
            for (j = 0; s[i] != tab[j]; j++);
                func[j](list);
        }
        else
            my_putchar(s[i]);
    }
}