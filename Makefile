##
## EPITECH PROJECT, 2019
## serveur
## File description:
## Makefile
##

NAME	= server

CC	= gcc

RM	= rm -f

SRCS	= ./src/cmd.c \
	  ./src/coin.c \
	  ./src/err_manag.c \
	  ./src/file_desc.c \
	  ./src/free_a.c \
	  ./src/game.c \
	  ./src/launcher.c \
	  ./src/main.c \
	  ./src/map.c \
	  ./src/player.c \
	  ./src/protocol.c \
	  ./src/server.c \
	  ./src/str_manip.c \
	  ./src/wall.c \
	  ./src/strtab.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./inc/
CFLAGS += -g
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
