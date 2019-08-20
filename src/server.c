/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** server
*/

#include "server.h"

void feel_data(data serv, _elem elm)
{
    FD_ZERO(&serv->set);
    FD_SET(serv->id, &serv->set);
    serv->nb_client = 0;
    serv->started = false;
    serv->_cmd = NULL;
    serv->_player = malloc(sizeof(struct player *) * 2);
    serv->gravity = atof(elm->gravity);
    serv->_map = new_map(elm->file);
}

void select_usr(data serv, fd_set *read_fd, fd_set *write_fd)
{
    struct timeval t;

    t.tv_usec = 50;
    t.tv_sec = 0;
    *write_fd = serv->set;
    *read_fd = serv->set;
    if (select(FD_SETSIZE, read_fd, write_fd, NULL, &t) < 0) {
        perror("select");
    }
}

int start_serv(data serv, _elem elm)
{
    feel_data(serv, elm);
    add_cmd(serv);
    fd_set read_fd;
    fd_set write_fd;
    while (1) {
        select_usr(serv, &read_fd, &write_fd);
        for (int i = 0; i < FD_SETSIZE; i++) {
            fd_read(serv, &read_fd, i);
            can_start(serv);
            if (is_started(serv))
                fd_write(serv, &write_fd, i);
        }
        if (is_started(serv)) {
            game_loop(serv);
            end(serv);
            wall(serv, serv->_player);
        }
    }
    return (0);
}