# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 22:11:06 by slyu              #+#    #+#              #
#    Updated: 2022/09/01 22:11:07 by slyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -g
FLAGS = -Wall -Wextra -Werror -g
TARGET = fractol
OBJ_INCLUDE = -I/usr/include -Imlx_linux -I. -I./minilibx-linux/ -I$(LIB_DIR)/
INCLUDE = -L./minilibx-linux/ -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -I./minilibx-linux/ -I. -I$(LIB_DIR)/
LIB_DIR = ./libft/
LIB = ft

SRCS = \
./main.c \
./image.c \
./hook.c \
./bounded.c \

HEADERS = fract_ol.h

OBJS = $(SRCS:.c=.o)

all: $(LIB) $(TARGET)

$(LIB):
	make -C $(LIB_DIR)

$(TARGET): $(OBJS) $(HEADERS)
	$(CC) $(FLAGS) -o $@ $^ $(INCLUDE) $(LIB_DIR)/lib$(LIB).a

%.o: %.c
	$(CC) $(CFLAGS) $< -o ${<:.c=.o} $(OBJ_INCLUDE)

clean:
	make clean -C $(LIB_DIR) 
	rm -f $(OBJS)

fclean:
	make fclean -C $(LIB_DIR) 
	rm -f $(OBJS) $(TARGET)

re : fclean all

.PHONY: all clean fclean re