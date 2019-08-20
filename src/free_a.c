/*
** EPITECH PROJECT, 2019
** serveur
** File description:
** free_a
*/

#include "server.h"

void clear_player(data serv, struct player *_player, int id)
{
    FD_CLR(_player->ID, &serv->set);
    close(_player->ID);
    free(_player);
    serv->_player[id] = NULL;
    serv->nb_client--;
}

void del_player(data serv, int id)
{
    for (int y = 0; y < 2; y++) {
        if (serv->started == false) {
            if (y == id && serv->_player[y] != NULL)
                clear_player(serv, serv->_player[y], y);
        } else
            clear_player(serv, serv->_player[y], y);
    }
}