/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** UP my string
*/

int my_strlen(char const *str);

int my_str_isupper(char const *str)
{
    int alpha = 0;

    if ( my_strlen(str) == 0)
        return (1);
    for (int letter = 0; str[letter] != '\0'; letter++)
        if (str[letter] >'A' && str[letter] < 'Z')
            alpha = 1;
        else{
            alpha = 0;
            break;
        }
    return alpha;
}
