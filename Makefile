# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 10:23:18 by sabdulla          #+#    #+#              #
#    Updated: 2022/11/22 12:34:30 by sabdulla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

SRC_NAME = client.c server.c
SRC_BONUS = client_bonus.c server_bonus.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: ${OBJ_NAME} ${SERVER} ${CLIENT}

${CLIENT}: ${OBJ_NAME}
	$(CC) $(CFLAGS) -o client client.o

${SERVER}: ${OBJ_NAME}
	$(CC) $(CFLAGS) -o server server.o

${CLIENT_BONUS}: ${OBJ_BONUS}
	$(CC) $(CFLAGS) -o client_bonus client_bonus.o

${SERVER_BONUS}: ${OBJ_BONUS}
	$(CC) $(CFLAGS) -o server_bonus server_bonus.o


bonus :${OBJ_BONUS} ${SERVER_BONUS} ${CLIENT_BONUS}

clean :
	rm -rf ${OBJ_NAME} ${OBJ_BONUS}

fclean: clean
	rm -f ${CLIENT} ${SERVER} ${CLIENT_BONUS} ${SERVER_BONUS} 

re: fclean all