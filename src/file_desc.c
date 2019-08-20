/*
** EPITECH PROJECT, 2019
** serveur
** File description:
** file_desc
*/

#include "server.h"

void fd_read(data serv, fd_set *read_fd, int id)
{
    if (FD_ISSET(id, read_fd)) {
        if (id == serv->id)
            add_player(serv);
        else
            read_player(serv, id);
    }
}

void fd_write(data serv, fd_set *write_fd, int id)
{
    int nb = 0;

    if (FD_ISSET(id, write_fd)) {
        if (id != serv->id) {
            disp_pos(serv->_player, id);
            coin(serv, serv->_player, id);
            for (; serv->_player[nb]->ID != id; nb++);
            nb == 1 ? clear_map(serv) : 0;
            is_end(serv, id);
        }
    }
}