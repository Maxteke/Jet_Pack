/*
** EPITECH PROJECT, 2019
** serveur
** File description:
** coin
*/

#include "server.h"

int is_round(float x, int *tb)
{
    float x1 = (int)x;

    if (x > x1) {
        tb[0] = x1;
        tb[1] = x1 + 1;
        return (2);
    }
    tb[0] = x1;
    return (1);
}

void coin(data serv, struct player **_player, int id)
{
    int y_m = serv->_map->y - 1;
    int *x1 = malloc(sizeof(int) * 2);
    int *y1 = malloc(sizeof(int) * 2);
    int x2 = 0;
    int y2 = 0;

    for (int i = 0; i < 2; i++) {
        x2 = is_round(_player[i]->x, x1);
        y2 = is_round(_player[i]->y, y1);
        for (int y = 0; y < y2; y++) {
            for (int x = 0; x < x2; x++) {
                if (serv->_map->_map[y_m - y1[y]][x1[x]] == 'c') {
                    dprintf(id, CON, serv->_player[i]->ID, x1[x], y1[y]);
                    _player[i]->ID == id ? serv->_player[i]->score++ : 0;
                }
            }
        }
    }
}