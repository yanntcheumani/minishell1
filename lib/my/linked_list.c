/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** library for linked_list
*/

#include "../../include/struct.h"
#include <stddef.h>
#include <stdlib.h>

void my_printf(char *str, ...);

void insert_node(linked_node_t *lists, char *file)
{
    node_t *node = malloc(sizeof(*node));
    node_t *last_node = lists->end;

    node->file = file;
    node->next = NULL;
    node->prev = lists->end;
    if (last_node == NULL) {
        lists->first = node;
        lists->end = node;
        return;
    }
    last_node->next = node;
    lists->end = node;
}

void print_list(linked_node_t *lists)
{
    for (node_t *i = lists->first; i != NULL; i = i->next) {
        if (i->file[0] != '.')
            my_printf("%s", i->file);
    }
    my_printf("\n");
}

void print_reverse_list(linked_node_t *lists)
{
    for (node_t *i = lists->end; i != NULL; i = i->prev) {
        if (i->file[0] != '.')
            my_printf("%s\n", i->file);
    }
}

linked_node_t *create_linked_node(linked_node_t *lists)
{
    lists = malloc(sizeof(linked_node_t));
    lists->end = NULL;
    lists->first = NULL;

    return (lists);
}

void swap_node(node_t *a, node_t *b)
{
    node_t c;

    c = *b;
    *b = *a;
    *a = c;
}
