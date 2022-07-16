# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 19:07:13 by slyu              #+#    #+#              #
#    Updated: 2022/07/16 19:07:15 by slyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -g
FLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
LIB_DIR = ./ft_printf
LIB = ftprintf
INCLUDE = -I$(LIB_DIR)

SERVER_SRCS = \
./server.c \
./common.c

CLIENT_SRCS = \
./client.c \
./common.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(LIB) $(SERVER) $(CLIENT)

$(LIB):
	make -C $(LIB_DIR)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(FLAGS) -o $@ $^ $(LIB_DIR)/lib$(LIB).a

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(FLAGS) -o $@ $^ $(LIB_DIR)/lib$(LIB).a

%.o: %.c
	$(CC) $(CFLAGS) $< -o ${<:.c=.o} $(INCLUDE)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean:
	make clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re