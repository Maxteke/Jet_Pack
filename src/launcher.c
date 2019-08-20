/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** launcher
*/

#include "server.h"

int bind_sock(data serv, _elem elm)
{
    if (bind(serv->id, (sock *)serv->s, sizeof(struct sockaddr_in)) == -1) {
        perror("bind");
        return (1);
    }
    if (listen(serv->id, 2)) {
        perror("listen");
        return (1);
    }
    return (start_serv(serv, elm));
}

int launch(_elem elm)
{
    data serv = malloc(sizeof(struct serv_data));

    serv->s = malloc(sizeof(struct sockaddr_in));
    serv->id = socket(AF_INET, SOCK_STREAM, 0);
    if (serv->id == -1) {
        perror("socket");
        return (84);
    }
    serv->s->sin_addr.s_addr = htonl(INADDR_ANY);
    serv->s->sin_family = AF_INET;
    serv->s->sin_port = htons(atoi(elm->port));
    return (bind_sock(serv, elm));
}