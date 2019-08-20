/*
** EPITECH PROJECT, 2019
** serveur
** File description:
** game
*/

#include "server.h"

void start(data serv)
{
    for (int i = 0; i < serv->nb_client; i++)
        dprintf(serv->_player[i]->ID, "START\n");
    serv->started = true;
}

void can_start(data serv)
{
    if (serv->nb_client < 2 && serv->started == true) {
        serv->started = false;
        free(serv->_map->_map);
        serv->_map->_map = clone_map(serv->_map->tmp);
    }
    if (serv->started == false && is_ready(serv))
        start(serv);
}

int is_started(data serv)
{
    return ((int)serv->started);
}

void is_end(data serv, int id)
{
    int i = 0;
    bool loose = false;

    for (; serv->_player[i]->ID != id; i++);
    if (serv->_player[0]->loose == true) {
        dprintf(id, WIN, serv->_player[1]->ID);
        loose = true;
    }
    else if (serv->_player[1]->loose == true) {
        dprintf(id, WIN, serv->_player[0]->ID);
        loose = true;
    }
    if (i == 1 && loose == true)
        del_player(serv, i);
}

void game_loop(data serv)
{
    for (int i = 0; i < serv->nb_client; i++) {
        if (serv->_player[i]->x < serv->_map->x - 1)
            serv->_player[i]->x += 0.01;
        if (serv->_player[i]->fire == true
            && serv->_player[i]->y < serv->_map->y - 1) {
                serv->_player[i]->y += 0.01;
                if (serv->_player[i]->y > serv->_map->y - 1)
                    serv->_player[i]->y = serv->_map->y - 1;
            }
        else if (serv->_player[i]->y > 0)
            serv->_player[i]->y -= 0.01;
    }
    usleep(1000);
}
