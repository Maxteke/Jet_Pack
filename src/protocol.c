/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** protocol
*/

#include "server.h"

void id_c(data serv, struct player *_player)
{
    if (serv)
        dprintf(_player->ID, IDC, _player->ID);
}

void map_c(data serv, struct player *player)
{
    dprintf(player->ID, MAP, serv->_map->x, serv->_map->y);
    for (int i = 0; serv->_map->_map[i] != NULL; i++)
        dprintf(player->ID, "%s", serv->_map->_map[i]);
    dprintf(player->ID, "\n");
}

void ready_c(data serv, struct player *player)
{
    if (serv)
        player->ready = true;
}

void fire_c(data serv, struct player *player)
{
    char **arg = str_to_tab(player->cmd, ' ');

    if (atoi(arg[1]) == 0)
        player->fire = false;
    else
        player->fire = true;
    for (int i = 0; arg[i] != NULL; i++)
        free (arg[i]);
    if (serv)
        free(arg);
}
