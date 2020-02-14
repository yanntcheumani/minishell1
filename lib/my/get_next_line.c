/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** main file
*/

#include <fcntl.h>
#include <unistd.h>
#include <zconf.h>
#include <stdlib.h>
#include "get_next_line.h"

int chek_it(char const  *str)
{
    int cases;

    for (cases = 0; str[cases]; cases++)
        if (str[cases] == '\n')
            return (84);
    return (0);
}

char *my_concate(char const *res, char const  *buffer, int size)
{
    int compteur = 0, compteur2 = 0;
    char *str;

    for (compteur = 0; res[compteur]; compteur++);
    str = malloc(sizeof(char) * (compteur + size + 1));
    if (str == NULL)
        return (NULL);
    for (compteur = 0; res[compteur]; compteur++)
        str[compteur] = res[compteur];
    for (; size != 0 && compteur2 < size; compteur2++)
        str[compteur + compteur2] = buffer[compteur2];
    str[compteur + size] = '\0';
    return (str);
}

char *my_scrap(char const  *str)
{
    int cases = 0, cases2 = 0;
    char *scrap = NULL;

    for (cases = 0; str[cases] && str[cases] != '\n'; cases++);
    (str[cases] == '\n') ? cases++ : cases;
    for (cases2 = 0; str[cases2]; cases2++);
    scrap = malloc(sizeof(char) * ((cases2 - cases) + 1));
    if (scrap == NULL)
        return (NULL);
    for (cases2 = 0; str[cases]; cases2++, cases++)
        scrap[cases2] = str[cases];
    scrap[cases2] = '\0';
    return (scrap);
}

char *get_next_line(int fd)
{
    static int weight = 1, start = 0;
    static char buffer[READ_SIZE];
    static char *temporary = "\0";
    char *scrap = "\0";
    int i;

    if (buffer == NULL || READ_SIZE <= 0 || fd == -1) return (NULL);
    for (i = 0; temporary[i]; i++);
    if (start++ != 0 && i != 0)
        if ((scrap = my_concate(temporary, NULL, 0)) == NULL)
            return (NULL);
    while (weight != 0 && (weight = read(fd, buffer, READ_SIZE)) > 0)
        if (((scrap = my_concate(scrap, buffer, weight))
             && chek_it(scrap) == 84) || !scrap)
            break;
    for (i = 0; temporary[i]; i++);
    if (scrap == NULL || (temporary = my_scrap(scrap)) == NULL ||
        weight == -1 || (weight == 0 && i == 0))
        return (NULL);
    for (int cases = 0; scrap[cases]; cases++)
        (scrap[cases] == '\n') ? scrap[cases] = '\0' : 0;
    return (scrap);
}
