/*
** EPITECH PROJECT, 2019
** my_strlowercase
** File description:
** dfd
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    char tmp[my_strlen(str)];

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z'){
            tmp[i] = str[i] + ('a' - 'A');
        }else{
            tmp[i] = str[i];
        }
    }
    str = tmp;
    return (str);
}
