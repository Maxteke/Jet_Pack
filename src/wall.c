/*
** EPITECH PROJECT, 2019
** serveur
** File description:
** wall
*/

#include "server.h"

void wall(data serv, struct player **_player)
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
                if (serv->_map->_map[y_m - y1[y]][x1[x]] == 'e') {
                    serv->_player[i]->loose = true;
                }
            }
        }
    }
}