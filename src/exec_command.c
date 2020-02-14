/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** file for execute commands and builtins
*/

#include <unistd.h>
#include <sys/wait.h>
#include "my.h"


int	run_cmd(minishell_t *all, char *path)
{
    pid_t pid = fork();;
    int statut;
    char **my_env;

    my_env = all->env_char;
    if (pid == -1) {
        my_error(ERROR_FORK, "ERREUR FORK");
        return (1);
    } else if (pid == 0) {
        if (execve(path, all->cmd, my_env) == -1) {
            my_error("Unknown command ", all->shell_cmd);
            return (1);
        }
    }
    else
        wait(&statut);
    return (0);
}

int cmd_error(minishell_t *shell)
{
    if (shell->bonus == 1) {
        my_error(RED, "Commande invalide : ");
        my_error(MAGENTA, shell->cmd[0]);
        my_error("\n", "\e[0;39m");
    }
    my_error(shell->cmd[0], ": Command not found.\n");
    return (1);
}

int exec_command(minishell_t *shell)
{
    char *cmd = NULL;

    if (my_strcmp(shell->cmd[0], "env") == 0)
        return (print_env(shell->env));
    if (my_strcmp(shell->cmd[0], "exit") == 0)
        return (my_exit());
	if (my_strcmp(shell->cmd[0], "cd") == 0)
		return (cd(shell, shell->cmd[1]));
    cmd = get_binpath(shell);
    if (cmd == NULL) return (cmd_error(shell));
    return (run_cmd(shell, cmd));
}
