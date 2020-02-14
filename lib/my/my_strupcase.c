/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** jdhfj
*/

int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    char tmp[my_strlen(str)];
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z'){
            tmp[i] = str[i] - ('a' - 'A');
        }else{
            tmp[i] = str[i];
        }
    }
    str = tmp;
    return (str);
}
