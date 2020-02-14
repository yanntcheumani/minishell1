/*
** EPITECH PROJECT, 2019
** my_str_is_lower
** File description:
** verif lower str
*/

int my_strlen(char const *str);

int my_str_islower(char const *str)
{
    int alpha = 0;

    if ( my_strlen(str) == 0)
        return (1);
    for (int letter = 0; str[letter] != '\0'; letter++) {
        if (str[letter] > 'a' && str[letter] < 'z')
            alpha = 1;
        else{
            alpha = 0;
            break;
        }
    }
    return alpha;
}
