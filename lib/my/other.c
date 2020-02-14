/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_power
*/

int my_power(int a)
{
    int	out = 1, i = 0;

    for (; i < a; i++)
        out = out * 10;
    return (out);
}
