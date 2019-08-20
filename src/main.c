/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** main
*/

#include "server.h"

int main(int ac, char **av)
{
    _elem elm = malloc(sizeof(struct elem));

    if (!check_err(ac, &av[1], elm))
        return (84);
    launch(elm);
    return (0);
}