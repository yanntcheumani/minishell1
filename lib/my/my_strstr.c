/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_strstr search stringa in stringb
*/

int is_same_str(char *a, char *b, int len)
{
    int i = 0;

    while (i < len && a[i] && b[i]) {
        if (a[i] != b[i])
            return (-1);
        i = i + 1;
    }
    if (i == len)
        return (0);
    return (-1);
}
