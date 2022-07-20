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
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
LIB_DIR = ./ft_printf
LIB = ftprintf
INCLUDE = -I$(LIB_DIR) -I./includes

SERVER_SRCS = \
./srcs/server.c \
./srcs/common.c

CLIENT_SRCS = \
./srcs/client.c \
./srcs/common.c

SERVER_INC = ./includes/server.h
CLIENT_INC = ./includes/client.h

SERVER_SRCS_BONUS = \
./bonus/server_bonus.c \
./bonus/common_bonus.c

CLIENT_SRCS_BONUS = \
./bonus/client_bonus.c \
./bonus/common_bonus.c

ifdef BONUS_FLAG
	SERVER_OBJS = $(SERVER_SRCS_BONUS:.c=.o)
	CLIENT_OBJS = $(CLIENT_SRCS_BONUS:.c=.o)
else
	SERVER_OBJS = $(SERVER_SRCS:.c=.o)
	CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
endif

all: $(LIB) $(SERVER) $(CLIENT)

$(LIB):
	make -C $(LIB_DIR)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(FLAGS) -o $@ $^ $(LIB_DIR)/lib$(LIB).a

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(FLAGS) -o $@ $^ $(LIB_DIR)/lib$(LIB).a

bonus:
	make BONUS_FLAG=1 all

%.o: %.c
	$(CC) $(CFLAGS) $< -o ${<:.c=.o} $(INCLUDE)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(SERVER_SRCS_BONUS:.c=.o) $(CLIENT_SRCS_BONUS:.c=.o) $(SERVER_SRCS:.c=.o) $(CLIENT_SRCS:.c=.o)

fclean:
	make clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus