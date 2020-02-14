/*
** EPITECH PROJECT, 2020
** lib
** File description:
** function utility for minishell
*/

#include <stdlib.h>
#include "my.h"

char *getenv_path(cmd_var *env)
{
    cmd_var *temp = malloc(sizeof(cmd_var));

    if (temp == NULL) return (NULL);
    temp = env;
    for (; temp != NULL; temp = temp->next)
        if (is_same_str(temp->name, "PATH", 4) == 0)
            return (temp->var);
    return (NULL);
}

int print_env(cmd_var *env)
{
    cmd_var *temporary_env = malloc(sizeof(cmd_var));

    if (temporary_env == NULL) return (42);
    temporary_env = env;
    for (; temporary_env != NULL; temporary_env = temporary_env->next) {
        my_putstr(temporary_env->name);
        my_putstr("=");
        my_putstr(temporary_env->var);
        my_putstr("\n");
    }
    return (0);
}

cmd_var *delete_env(cmd_var *env, char *delete)
{

    cmd_var *temp = malloc(sizeof(cmd_var));
    cmd_var *del_temp;

    if (env == NULL || delete == NULL || temp == NULL) return (NULL);
    temp = env;
    while (temp->next != NULL) {
        if (my_strcmp(temp->next->name, delete) == 0) {
	        temp->next = temp->next->next;
	        del_temp = temp->next;
            free(del_temp);
            return (env);
        }
        temp = temp->next;
    }
    return (env);
}

cmd_var *add_environnement(cmd_var *src, char *str, char *var)
{
    cmd_var *new = malloc(sizeof(cmd_var));
    cmd_var *temp = malloc(sizeof(cmd_var));

    if (new == NULL || temp == NULL || str == NULL) return (NULL);
    new->name = str;
    new->next = NULL;
    new->var = var;
    if (src == NULL) return (new);
    for (temp = src; temp->next != NULL; temp = temp->next);
    temp->next = new;
    return (src);
}
