/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** ldmfmdlfmdl
*/

int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int alpha = 0;

    if (my_strlen(str) == 0) return (1);
    for (int letter = 0; str[letter] != '\0'; letter++)
        if (str[letter] >= '0' && str[letter] <= '9')
            alpha = 1;
        else{
            alpha = 0;
            break;
        }
    return alpha;
}
