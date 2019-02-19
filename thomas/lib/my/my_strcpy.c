/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Day06 , task01
*/

char *my_strcpy(char *dest, char const *src)
{
    int j = 0;

    while (src[j] != '\0') {
        dest[j] = src[j];
        j++;
    }
    if (dest[j] = '\0')
        return (dest);
}
