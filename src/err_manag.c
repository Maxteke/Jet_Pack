/*
** EPITECH PROJECT, 2019
** serveur
** File description:
** err_manag
*/

#include "server.h"

int num(char *str, int f)
{
    for (int i = 0; str[i]; i++) {
        if (!f) {
            if (!isdigit(str[i]))
                return (0);
        } else {
            if (!isdigit(str[i]) && str[i] != '.')
                return (0);
        }
    }
    return (1);
}

char *cp_str(const char *av)
{
    char *tmp = malloc(sizeof(char) + (strlen(av)));
    strcpy(tmp, av);
    return (tmp);
}

int access_f(char *str)
{
    if (access(str, O_RDONLY) == -1)
        return (0);
    if (!check_map(open(str, O_RDONLY)))
        return (0);
    return (1);
}

int flagc(char **av, _elem elm)
{
    if (!strcmp(av[0], "-p")) {
        if (num(av[1], 0))
            elm->port = cp_str(av[1]);
        else return (0);
    } else if (!strcmp(av[0], "-g")) {
        if (num(av[1], 1))
            elm->gravity = cp_str(av[1]);
        else return (0);
    } else if (!strcmp(av[0], "-m")) {
        if (access_f(av[1]))
            elm->file = cp_str(av[1]);
        else return (0);
    } else return 0;
    return (1);
}

int check_err(int ac, char **av, _elem elm)
{
    if (ac != 7)
        return (0);
    for (int i = 0; av[i] != NULL; i++) {
        if (av[i + 1] != NULL) {
            if (!flagc(&av[i], elm))
                return (0);
            i++;
        }
    }
    return (1);
}