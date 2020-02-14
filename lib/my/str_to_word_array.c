/*
** EPITECH PROJECT, 2020
** lib
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

int	number_of_words(char *src)
{
    int i = 0;
    int number_letter = (src[0] == ' ' || src[0] == '\t') ? 0 : 1;;

    for (; src[i]; i++)
        if (src[i - 1] == ' ' && src[i] != ' ' && src[i] != '\t')
            number_letter = (i > 0) ? number_letter + 1 : number_letter;
    return (number_letter);
}

char *get_word(char const *src, int *pos, int len)
{
    char *out = malloc(sizeof(char) * len);
    int	j = 0;

    if (out == NULL) return (NULL);
    for (; src[*pos] && src[*pos] != ' '; j++, *pos = *pos + 1)
        out[j] = src[*pos];
    while (src[*pos] && (src[*pos] == ' ' || src[*pos] == '\t'))
        *pos = *pos + 1;
    return (out);
}

char **strtab(char *src)
{
    int nbwords = number_of_words(src), i = 0, pos = 0, max =  my_strlen(src);
    char **str_return =  malloc(sizeof(char *) * (nbwords + 1));;

    if (src == NULL) return (NULL);
    if (str_return == NULL) return (NULL);
    for (; i < nbwords; i++) {
        str_return[i] = get_word(src, &pos, max);
        if (str_return[i] == NULL) return (NULL);
    }
    str_return[i] = NULL;
    return (str_return);
}
