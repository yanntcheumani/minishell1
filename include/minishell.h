/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** struct of minishell
*/

#ifndef __MINISHELL__
#define __MINISHELL__

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define MAGENTA "\033[1;35m"
# define BLUE "\033[1;34m"
# define ERROR_FORK "erreur fork"

typedef struct	s_hist
{
    char		*str;
} t_hist;

typedef struct	cmd_var
{
    char *name;
    char *var;
    struct cmd_var *next;
} cmd_var;

typedef struct minishell_s
{
    int		bonus;
    char *shell_cmd;
    char **cmd;
    cmd_var *env;
    char **env_char;
    char *loca;
    char *floca;
    char *home_fold;
    char *name;
    int	bin;
    int	result;
} minishell_t;

int my_exit(void);
#endif
