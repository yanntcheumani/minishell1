/*
** EPITECH PROJECT, 2020
** lib
** File description:
** putstr for error
*/

#include <unistd.h>
#include "my.h"

void my_puterror(char c)
{
    if (c)
        write(2, &c, 1);
}

void my_putserror(char *c)
{
    int i = 0;

    if (c == NULL) return ;
    while (c[i]) {
        my_puterror(c[i]);
        i = i + 1;
    }
}

void my_error(char *a, char *b)
{
    my_putserror(a);
    my_putserror(b);
}
