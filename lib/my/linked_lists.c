/*
** EPITECH PROJECT, 2020
** librarye linked_list
** File description:
**  part II
*/
#include "../../include/struct.h"
#include <stddef.h>
#include <stdlib.h>

int count_node(linked_node_t *lists)
{
    int len = 0;

    for (node_t *i = lists->first; i != NULL; i = i->next, len++);
    return (len);
}

void linked_list_init(linked_node_t *s)
{
    s->first = NULL;
    s->end = NULL;
}

node_t *recup_node(linked_node_t *list, int position)
{
    node_t *node = list->first;

    if (position >= count_node(list))
        return (NULL);
    for (int i = 0; i != position; node = node->next, i++);
    return (node);
}