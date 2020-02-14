/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** parse wave
*/

#include <stdlib.h>
#include "my.h"

char *delete_wave(char const *src)
{
    int i = 1;
    char *str = malloc(sizeof(char) * my_strlen(src));

    if (str == NULL) return (NULL);
    for (; src[i]; i++)
        str[i - 1] = src[i];
    str[i - 1] = '\0';
    return (str);
}

char **detect_wave(minishell_t *all, char **src)
{
    int i = 0;

    if (src == NULL) return (NULL);
    for (; src[i] != NULL; i++) {
        if (src[i][0] == '~')
            src[i] = my_concat(all->home_fold, delete_wave(src[i]));
        if (src[i] == NULL) return (NULL);
    }
    src[i] = NULL;
    return (src);
}
