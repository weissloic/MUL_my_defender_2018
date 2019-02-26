/*
** EPITECH PROJECT, 2018
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_show_word_array(char * const *);
int bug();
int error(int, int, int, char **);
int cat(int ac, char **);
void infinadd(char *, char *);
void print_func(char *, va_list);
int my_printf(char *, ...);
long my_put_pointer(long);
void my_put_pointer_display(va_list);
int my_put_nbr(int);
void my_put_binary_display(va_list);
int my_put_hexa(int);
void my_put_hexa_display(va_list);
int my_put_hexa_up(int);
void my_put_hexa_up_display(va_list);
int my_put_binary(int);
void my_put_binary_display(va_list);
int my_put_octal(int);
void my_put_octal_display(va_list);
void my_put_nbr_display(va_list);
void my_putstr_display(va_list);
void my_putchar_display(va_list);
void my_unsigned_putnbr_display(va_list);
unsigned int my_unsigned_putnbr(unsigned int);
unsigned char *my_full_putstr(unsigned char *);
void my_full_putstr_display(va_list);

static void (*func[11])(va_list) = {
    &my_put_nbr_display,
    &my_put_nbr_display,
    &my_putstr_display,
    &my_putchar_display,
    &my_put_pointer_display,
    &my_put_hexa_display,
    &my_put_hexa_up_display,
    &my_put_binary_display,
    &my_put_octal_display,
    &my_unsigned_putnbr_display,
    &my_full_putstr_display
};

#endif //MY_H
