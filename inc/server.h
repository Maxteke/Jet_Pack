/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>
#include "protocol.h"
#include <stdbool.h>

typedef struct serv_data *data;
typedef struct elem *_elem;
typedef struct sockaddr sock;

struct player
{
    float x;
    float y;
    int ID;
    char *cmd;
    int score;
    bool ready;
    bool fire;
    bool loose;
};

struct map
{
    int x;
    int y;
    char **_map;
    char **tmp;
};


struct cmd
{
    char *name;
    void (*func)(data, struct player *);
};

struct elem
{
    char *port;
    char *file;
    char *gravity;
};

struct serv_data
{
    int id;
    fd_set set;
    struct sockaddr_in *s;
    struct player **_player;
    int nb_client;
    struct cmd **_cmd;
    struct map *_map;
    bool started;
    float gravity;
};


char **clone_map(char **);
void end(data);
void wall(data, struct player **);
void is_end(data, int);
void del_player(data, int);
void clear_map(data);
int is_round(float, int *);
void coin(data, struct player **, int);
int is_started(data);
int check_map(int);
int check_err(int, char **, _elem);
void add_player(data);
int is_ready(data);
void can_start(data);
void ready_c(data, struct player *);
void fd_read(data, fd_set *, int);
void fd_write(data, fd_set *, int);
void game_loop(data);
void read_player(data, int);
char *get_file(int);
void disp_pos(struct player **, int);
char **str_to_tab(char *str, char);
void add_cmd(data);
void ready_c(data, struct player *);
void fire_c(data, struct player *);
void check_cmd(data, struct player *);
void *client_thread(void *);
void cmd_player(void *);
void id_c(data, struct player *);
void map_c(data serv, struct player *player);
int launch(_elem);
void create_player(data);
int start_serv(data, _elem);
struct player *new_player(int);
char *get_line(int);
struct map *new_map(char *);

#endif /* !SERVER_H_ */