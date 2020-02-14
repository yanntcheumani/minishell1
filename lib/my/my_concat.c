/*
** EPITECH PROJECT, 2020
** minishel
** File description:
** my_concat
*/

#include <stdlib.h>
#include "my.h"

char *home_delete(char *home, char *path)
{
    char *out = malloc(sizeof(char) * my_strlen(path));
    int i = 0;
    int j = 0;

    if (out == NULL || home == NULL || path == NULL) return (NULL);
    for (; home[i] && path[i] && home[i] == path[i]; i++);
    while (path[i]) {
        out[j] = path[i];
        j = j + 1;
        i = i + 1;
    }
    out[j] = 0;
    return (out);
}

char *my_concat(char *str, char *str2)
{
    char *out = malloc(sizeof(char) * (my_strlen(str) + my_strlen(str2)));
    int i = 0, j = 0;

    if (str == NULL || str2 == NULL || out == NULL) return (NULL);
    for (; str[i]; i++)
        out[i] = str[i];
    while (str2[j]) {
        out[i + j] = str2[j];
        j = j + 1;
    }
    out[i + j] = 0;
    return (out);
}
