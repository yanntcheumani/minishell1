/*
** EPITECH PROJECT, 2019
** my_count_line and count_rows
** File description:
** count line and columns
*/

int count_columns(char const *str)
{
    int compteur = 0;

    for (int cases = 0; str[cases] != '\0'; cases++) {
        if (str[cases] == '\n')
            compteur++;

    }
    return compteur;
}

int count_rows(char const *str)
{
    int compteur = 0;

    for (int cases = 0; str[cases] != '\n'; compteur++, cases++);
    return compteur;
}
