/*
** EPITECH PROJECT, 2019
** my_import
** File description:
** task02 day09
*/

#ifndef MY_IMPORT
#define MY_IMPORT

#include <stdarg.h>
#include "minishell.h"

void my_printf(char *str, ...);
void my_putchar(char c);
void my_putstr(char const *str);
void my_put_str(va_list list);
void my_putnbr(va_list list);
void my_put_char(va_list list);
void my_put_nbr_unsigned(unsigned int);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char const *str);
int my_strlen(char const *str);
char *get_next_line(int fd);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
char **env_to_char(minishell_t *);
char *getenv_path(cmd_var *);
char *get_binpath(minishell_t *);
char *get_cur_dir();
char *get_username(minishell_t *);
char *home_delete(char *, char *);
char *my_concat(char *, char *);
char **detect_wave(minishell_t *all, char **src);
char *get_ft(char *, int, char, int *);
char **strtab(char *);
char *get_ft_car(char *, char, char, int *);
int	init_shell(minishell_t *shell);
int	is_same_str(char *, char *, int);
int	minishell(minishell_t *);
int	exec_command(minishell_t *shell);
int	my_setenv(minishell_t *, char **);
int	my_unsetenv(minishell_t *, char **);
int	print_env(cmd_var *);
void my_error(char *, char *);
void print_cmd(minishell_t *shell);
cmd_var *add_environnement(cmd_var *src, char *str, char *var);
cmd_var *delete_env(cmd_var *env, char *delete);
void print_start(minishell_t *);
cmd_var *add_environnement(cmd_var *src, char *str, char *var);
cmd_var *delete_env(cmd_var *, char *);
cmd_var *get_env(minishell_t *);
#endif