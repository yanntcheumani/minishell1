/*
** EPITECH PROJECT, 2019
** STRCMP
** File description:
** compare to string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
