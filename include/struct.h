/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct for square
*/

#ifndef MINISHELL
#define MINISHELL

typedef struct node_s{
    char *file;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct linked_node_s {
    struct node_s *first;
    int nbr_arg;
    struct node_s *end;
}linked_node_t;

#endif