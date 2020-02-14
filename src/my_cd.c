/*
** EPITECH PROJECT, 2020
** my_cd.c
** File description:
** cd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_cd_continue(minishell_t *all, char *path)
{
	if (access(path, R_OK) == -1) {
		my_error(RED, "Error : [cd] can't access to ");
		my_error(MAGENTA, path);
		my_error(RED, " \n\e[0;39m");
		return (-1);
	}
	if (chdir(path) == -1) {
		my_error(RED, "Error : [cd] Directory Locked or it's a File ");
		my_error(MAGENTA, path);
		my_error(RED, " Try with 'sudo'\n\e[0;39m");
		return (-1);
	}
	all->floca = path;
	return (0);
}

int	cd(minishell_t *shell, char *path)
{
	char *oldpwd = shell->env_char[36];

	if (my_strcmp(path, "-") == 0)
		return (my_cd_continue(shell, oldpwd + 7));
	if (path == NULL) {
		my_error(RED, "Error : [cd] ");
		my_error(MAGENTA, "usage : cd [PATH]");
		my_error("\e[0;39m", "\n");
		return (-1);
	}
	if (access(path, F_OK) == -1) {
		my_error(RED, "Error : [cd] ");
		my_error(MAGENTA, path);
		my_error(RED, " doesnt exist\n");
		my_error("", "\e[0;39m");
		return (-1);
	}
	return (my_cd_continue(shell, path));
}

char *cd_parse(minishell_t *shell, char *path)
{
	char *out;

	out = my_concat(shell->loca, path);
	return (out);
}

char *cd_delete_wave(minishell_t *shell, char *path)
{
	char *out;

	if (my_strlen(path) < 1)
		return (NULL);
	out = my_concat(shell->home_fold, path);
	return (out);
}
