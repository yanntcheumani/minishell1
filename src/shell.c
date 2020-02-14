/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** startup shell
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *copy_ab(char *str)
{
    int	i = 0, max = my_strlen(str);
    char *str_return = malloc(max * sizeof(char));

    if (str_return == NULL || str == NULL) return (NULL);
    for (; i < max; i++)
        str_return[i] = str[i];
    str_return[i] = '\0';
    return (str_return);
}

char *get_cur_dir(void)
{
    char	buff[1024];

    return (copy_ab(getcwd(buff, 1024)));
}

char *get_home_fd(char *name)
{
    return (my_concat("/home/", name));
}

char *get_username(minishell_t *all)
{
    int i;

    for (i = 0; all->env_char[i] != NULL; i++)
        if (is_same_str(all->env_char[i], "USER=", 5) == 0)
            return (get_ft(all->env_char[i], 5, 0, &all->bin));
    return (NULL);
}

int init_shell(minishell_t *shell)
{
    char buff[1024];

    shell->name = get_username(shell);
    shell->result = 0;
    shell->env = get_env(shell);
    shell->home_fold = get_home_fd(shell->name);
    shell->floca = copy_ab(getcwd(buff, 1024));
    shell->loca = home_delete(shell->home_fold, shell->floca);
    return (0);
}
