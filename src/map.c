/*
** EPITECH PROJECT, 2019
** serveur
** File description:
** file_manag
*/

#include "server.h"

void end(data serv)
{
    for (int i = 0; i < serv->nb_client; i++) {
        if (serv->_player[i]->x >= serv->_map->x - 1) {
            if (serv->_player[0]->score > serv->_player[1]->score)
                serv->_player[1]->loose = true;
            else if (serv->_player[0]->score < serv->_player[1]->score)
                serv->_player[0]->loose = true;
            else {
                serv->_player[0]->loose = true;
                serv->_player[1]->loose = true;
            }
        }
    }
}

void clear_map(data serv)
{
    int y_m = serv->_map->y - 1;
    int *x1 = malloc(sizeof(int) * 2);
    int *y1 = malloc(sizeof(int) * 2);
    int x2 = 0;
    int y2 = 0;

    for (int i = 0; i < 2; i++) {
        x2 = is_round(serv->_player[i]->x, x1);
        y2 = is_round(serv->_player[i]->y, y1);
        for (int y = 0; y < y2; y++) {
            for (int x = 0; x < x2; x++) {
                serv->_map->_map[y_m - y1[y]][x1[x]] = '_';
            }
        }
    }
}

struct map *new_map(char *file)
{
    struct map *_map = malloc(sizeof(struct map));
    int fd = open(file, O_RDONLY);
    int i = 0;

    _map->tmp = str_to_tab(get_file(fd), '\n');
    _map->_map = clone_map(_map->tmp);
    for (; _map->_map[i] != NULL; i++);
    _map->x = strlen(_map->_map[0]);
    _map->y = i;
    close(fd);
    return (_map);
}

int check_map(int fd)
{
    char c;
    int y = 0;
    int x = 0;

    while (read(fd, &c, 1)) {
        if (c != '\n') {
            if (c != 'e' && c != 'c' && c != '_')
                return (0);
            x++;
        }
        else {
            if (x > 0)
                y++;
            x = 0;
        }
    }
    if (y > 1)
        return (1);
    return (0);
}

