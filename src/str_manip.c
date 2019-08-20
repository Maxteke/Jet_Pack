/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** str_manip
*/

#include "server.h"

char *my_ralloc(char *str, int *s_max)
{
    char *tmp = malloc(*s_max * 2 + 1);
    int i = -1;

    while (++i < *s_max)
        tmp[i] = str[i];
    *s_max = *s_max * 2 + 1;
    free(str);
    return (tmp);
}

char *add_char(char *str, int *s, int *s_max, char c)
{
    if (*s == *s_max)
        str = my_ralloc(str, s_max);
    str[*s] = c;
    *s = *s + 1;
    return (str);
}

char *get_line(int fd)
{
    char c;
    char *str = malloc(4);
    int s = 0;
    int s_max = 4;

    while (1) {
        if (read(fd, &c, 1) > 0) {
            if (c == '\n')
                    return (add_char(str, &s, &s_max, '\0'));
            else
                    str = add_char(str, &s, &s_max, c);
        } else {
            free(str);
            return (0);
        }
    }
}

char *get_file(int fd)
{
    char c;
    char *str = malloc(4);
    int s = 0;
    int s_max = 4;

    while (read(fd, &c, 1))
        str = add_char(str, &s, &s_max, c);
    str = add_char(str, &s, &s_max, '\0');
    if (str[0] == '\0') {
        free (str);
        return (NULL);
    }
    return (str);
}

char **clone_map(char **map)
{
    char **tmp = NULL;
    int size = 0;

    for (; map[size] != NULL; size++);
    tmp = malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) {
        tmp[i] = malloc(sizeof(char) * strlen(map[i]));
        strcpy(tmp[i], map[i]);
    }
    tmp[size] = NULL;
    return (tmp);
}