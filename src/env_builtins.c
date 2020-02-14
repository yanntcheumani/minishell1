/*
** EPITECH PROJECT, 2020
** minishell3
** File description:
** file for edit env
*/

#include <stdlib.h>
#include "my.h"

int my_unsetenv(minishell_t *shell, char **delete)
{
    cmd_var *temp;

    if (delete[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (1);
    }
    temp = delete_env(shell->env, delete[1]);
    if (temp == NULL) return (1);
	shell->env = temp;
    return (0);
}

int my_setenv(minishell_t *shell, char **cmd)
{
    if (cmd == NULL) return (1);
    if (cmd[0] == NULL) return (1);
    if (cmd[1] == NULL) return (print_env(shell->env));
    if (cmd[2] == NULL) return (1);
    shell->env = delete_env(shell->env, cmd[1]);
    if (shell->env == NULL) return (1);
    shell->env = add_environnement(shell->env, cmd[1], cmd[2]);
    if (shell->env == NULL) return (1);
    return (0);
}

cmd_var *get_env(minishell_t *shell)
{
    int i = 0;
    cmd_var *start = NULL;

    for (; shell->env_char[i]; i++) {
        start = add_environnement(start, get_ft(shell->env_char[i], 0, '=', &shell->bin),
                                  get_ft_car(shell->env_char[i], '=', 0, &shell->bin));
        if (start == NULL) return (NULL);
    }
    return (start);
}
