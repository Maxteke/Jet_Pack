/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** player
*/

#include "server.h"

struct player *new_player(int ID)
{
    struct player *tmp;

    tmp = malloc(sizeof(struct player));
    tmp->ID = ID;
    tmp->x = 0;
    tmp->y = 0;
    tmp->score = 0;
    tmp->cmd = NULL;
    tmp->ready = false;
    tmp->fire = false;
    tmp->loose = false;
    return (tmp);
}

void read_player(data serv, int id)
{
    int y = 0;

    for (; y < serv->nb_client; y++) {
        if (serv->_player[y]->ID == id) {
            serv->_player[y]->cmd = get_line(id);
            break;
        }
    }
    if (serv->_player[y]->cmd == NULL)
        del_player(serv, y);
    else {
        check_cmd(serv, serv->_player[y]);
        free(serv->_player[y]->cmd);
        serv->_player[y]->cmd = NULL;
    }
}

void add_player(data serv)
{
    struct sockaddr_in c;
    size_t len = sizeof(c);
    int csock = 0;

    csock = accept(serv->id , (sock *)&c, (socklen_t *)&len);
    if (serv->nb_client < 2) {
        for (int i = 0; i < 2; i++) {
            if (serv->_player[i] == NULL) {
                serv->_player[i] = new_player(csock);
                break;
            }
        }
        FD_SET(csock, &serv->set);
        serv->nb_client++;
    }
    else {
        dprintf(csock, "Sorry to many player :x\n");
        close(csock);
    }
}

void disp_pos(struct player **_player, int id)
{
    if (_player[0] != NULL && _player[1] != NULL) {
        dprintf(id, PLA, _player[0]->ID
        , _player[0]->x, _player[0]->y, _player[0]->score);
        dprintf(id, PLA, _player[1]->ID
        , _player[1]->x, _player[1]->y, _player[1]->score);
    }
}

int is_ready(data serv)
{
    if (serv->nb_client < 2)
        return (0);
    for (int i = 0; i < serv->nb_client; i++) {
        if (serv->_player[i]->ready != true)
            return (0);
    }
    return (1);
}