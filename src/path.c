/*
** EPITECH PROJECT, 2020
** minisell
** File description:
** edit path env
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int count_double_point(char *src)
{
    int i = 0, out = 0;

    if (src == NULL) return (0);
    for (; src[i]; i++)
        if (src[i] == ':')
            out = out + 1;
    return (out);
}

char **arr_to_path(char *src)
{
    int i = 0, max = count_double_point(src), pos = 0;
    char **str = malloc(sizeof(char *) * (max + 1));

    if (max == 0)
        max = 1;
    if (str == NULL) return (NULL);
    for (; i < max; i++) {
        str[i] = get_ft(src, pos, ':', &pos);
        if (str[i] == NULL)
            return (NULL);
        pos = pos + 1;
    }
    str[i] = NULL;
    return (str);
}

char *find_path(char *bin, char **src)
{
    char *temp = NULL;
    int i = 0;

    if (src == NULL) return (NULL);
    for (; src[i] != NULL; i++) {
        temp = my_concat(my_concat(src[i], "/"), bin);
        if (access(temp, F_OK | X_OK) != -1)
            return (my_concat(my_concat(src[i], "/"), bin));
    }
    return (NULL);
}

char *get_binpath(minishell_t *shell)
{
    char *str;
    char **path;

    if (access(shell->cmd[0], F_OK | X_OK) == 0) {
        str = my_concat(shell->floca, "/");
        return (my_concat(str, shell->cmd[0]));
    }
    path = arr_to_path(getenv_path(shell->env));
    str = find_path(shell->cmd[0], path);
    return (str);
}
