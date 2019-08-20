/*
** EPITECH PROJECT, 2019
** serveur
** File description:
** strtab
*/

#include "server.h"

int countspace(char *str, char c)
{
    int i = 0;
    int ret = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            ret++;
        i++;
    }
    return (ret);
}

void my_strncpy(char *src, char *dest, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
}

int lenghofstr(char *str, int i, char c)
{
    int ret = 0;

    while (str[i] != '\0' && str[i] != c) {
        i = i + 1;
        ret++;
    }
    return (ret);
}

char **str_to_tab(char *str, char to_break)
{
    int i = 0;
    int j = 0;
    int charlen;
    int spaces = countspace(str, to_break);
    char **params = malloc(sizeof(char *) * (spaces + 2));

    while (i < (int)strlen(str)) {
        charlen = lenghofstr(str, i, to_break);
        if (charlen > 0) {
            params[j] = malloc(sizeof(char) * (charlen + 1));
            params[j][charlen] = '\0';
            my_strncpy(&str[i], params[j], charlen);
            j++;
            i += charlen;
        }
        else
            i++;
    }
    params[j] = 0;
    return (params);
}