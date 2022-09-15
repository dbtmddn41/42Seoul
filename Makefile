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

CC = cc
CFLAGS = -Wall -Wextra -Werror -c -g
FLAGS = -Wall -Wextra -Werror -g
TARGET = fractol
OBJ_INCLUDE = -I/usr/include -Imlx_linux -I. -I./minilibx-linux/ -I$(LIB_DIR)
INCLUDE = -L./minilibx-linux/ -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -I./minilibx-linux/ -I. -I$(LIB_DIR)
LIB_DIR = ./libft/
LIB = ft
MLX_LIB_DIR = ./mlx/
MLX_LIB = mlx

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
OBJ_INCLUDE = -I/usr/include -Imlx_linux -Iincludes -I./minilibx-linux/ -I$(LIB_DIR)
INCLUDE = -L./minilibx-linux/ -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -I./minilibx-linux/ -Iincludes -I$(LIB_DIR)
endif
ifeq ($(UNAME), Darwin)
OBJ_INCLUDE = -Imlx -I$(LIB_DIR) -Iincludes
INCLUDE = -L$(MLX_LIB) -I$(MLX_LIB) -framework OpenGL -framework AppKit -Iincludes -I$(LIB_DIR)
endif

SRCS = \
./srcs/main.c \
./srcs/image.c \
./srcs/hook.c \
./srcs/bounded.c \
./srcs/newton.c \
./srcs/others.c \
./srcs/move.c \
./srcs/utils.c \
./srcs/colors.c

HEADERS = ./includes/fract_ol.h

OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(LIB) $(TARGET)

$(MLX_LIB):
	make -C $(MLX_LIB_DIR)
	cp $(MLX_LIB_DIR)libmlx.dylib .

$(LIB):
	make -C $(LIB_DIR)

$(TARGET): $(OBJS) $(HEADERS)
	make -C $(MLX_LIB_DIR)
	cp $(MLX_LIB_DIR)libmlx.dylib .
	$(CC) $(FLAGS) -o $@ $(OBJS) $(INCLUDE) $(LIB_DIR)lib$(LIB).a lib$(MLX_LIB).dylib

%.o: %.c
	$(CC) $(CFLAGS) $< -o ${<:.c=.o} $(OBJ_INCLUDE)

clean:
	make clean -C $(MLX_LIB_DIR)
	make clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean:
	make clean -C $(MLX_LIB_DIR)
	make fclean -C $(LIB_DIR) 
	rm -f lib$(MLX_LIB).dylib
	rm -f $(OBJS) $(TARGET)

re : fclean all

.PHONY: all clean fclean re