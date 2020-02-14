/*
** EPITECH PROJECT, 2020
** lib
** File description:
** get char or get str
*/

#include <stdlib.h>
#include "my.h"

int my_stlen_two(char *src, int start, char end)
{
    if (src == NULL) return (0);
    for (; src[start] && src[start] != end; start = start + 1);
    return (start);
}

char *get_ft(char *src, int start, char end, int *save)
{
    char *out = malloc(sizeof(char) * my_stlen_two(src, start, end));
    int i = 0;

    if (src == NULL) {
        *save = -1;
        return (NULL);
    }
    if (out == NULL) {
        *save = -1;
        return (NULL);
    }
    while (src[start] && src[start] != end)
        out[i++] = src[start++];
    *save = start;
    if (src[start] == 0)
        *save = -1;
    out[i] = '\0';
    return (out);
}

char *get_ft_car(char *src, char start, char end, int *save)
{
    int i = 0, j = 0;
    char *out = malloc(sizeof(char) * my_stlen_two(src, 0, end));

    if (src == NULL) return (NULL);
    if (out == NULL) return (NULL);
    for (; src [j] && src[j] != start; j++);
    j = j + 1;
    while (src[j] && src[j] != end)
        out[i++] = src[j++];
    *save = j;
    if (src[j] == 0)
        *save = -1;
    out[i] = '\0';
    return (out);
}
