/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main file
*/

#include <stdlib.h>
#include "my.h"

void print_cmd_continue(minishell_t *shell)
{
    my_putstr(BLUE);
    my_putstr(shell->floca);
    if (shell->result != 0)
        my_putstr(RED);
    else
        my_putstr(GREEN);
    my_putstr(" $ ");
    my_putstr("\e[0;39m");
    my_putstr("\e[96m");
}

void print_cmd(minishell_t *shell)
{
    if (is_same_str(shell->name, "root", 4) == 0) {
        my_putstr(BLUE);
        my_putstr(shell->floca);
        if (shell->result != 0)
            my_putstr(RED);
        else
            my_putstr(GREEN);
        my_putstr(" $ ");
        my_putstr("\e[0;39m");
    } else
        return (print_cmd_continue(shell));
}

int my_exit(void)
{
    my_putstr("exit\n");
    exit(0);
}

int minishell(minishell_t *shell)
{
    int loop = 0;

    if (init_shell(shell) != 0) return (1);
    shell->result = 0;
    while (loop == 0) {
        shell->name = get_username(shell);
	    print_cmd(shell);
        shell->shell_cmd = get_next_line(0);
        if (shell->shell_cmd == NULL) return (my_exit());
        shell->cmd = detect_wave(shell, strtab(shell->shell_cmd));
        if (shell->cmd == NULL) return (my_exit());
        my_putstr("\e[0;39m");
        shell->result = exec_command(shell);
        if (shell->result == 66) return (my_exit());
        shell->floca = get_cur_dir();
        if (shell->floca == NULL) return (EXIT_FAILURE);
    }
}

int	main(int ac, char **arg, char **env)
{
    minishell_t *shell = malloc(sizeof(minishell_t));

    if (env == NULL) return (1);
    shell->env_char = env;
    minishell(shell);
    return (EXIT_SUCCESS);
}
