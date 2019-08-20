/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** cmd
*/

#include "server.h"

struct cmd *new_cmd(void (*pt)(data, struct player *), char *str)
{
    struct cmd *tmp;

    tmp = malloc(sizeof(struct cmd));
    tmp->name = malloc(sizeof(char));
    sprintf(tmp->name, str);
    tmp->func = (*pt);
    return (tmp);
}

void add_cmd(data serv)
{
    serv->_cmd = malloc(sizeof(struct cmd *) * 5);
    serv->_cmd[0] = new_cmd(&id_c, "ID");
    serv->_cmd[1] = new_cmd(&map_c, "MAP");
    serv->_cmd[2] = new_cmd(&ready_c, "READY");
    serv->_cmd[3] = new_cmd(&fire_c, "FIRE");
    serv->_cmd[4] = NULL;
}

void check_cmd(data serv, struct player *_player)
{
    char **arg = str_to_tab(_player->cmd, ' ');

    for (int i = 0; serv->_cmd[i] != 0; i++)
        if (!strcmp(arg[0], serv->_cmd[i]->name))
            (*serv->_cmd[i]->func)(serv, _player);
    for (int i = 0; arg[i] != NULL; i++)
        free (arg[i]);
    free(arg);
    free (_player->cmd);
    _player->cmd = NULL;
}