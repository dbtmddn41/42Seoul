# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 02:12:04 by slyu              #+#    #+#              #
#    Updated: 2022/08/17 02:12:06 by slyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -g
FLAGS = -Wall -Wextra -Werror -g
TARGET = push_swap
LIB_DIR = ./ft_printf
LIB = ftprintf
INCLUDE = -I$(LIB_DIR)/includes -I$(LIB_DIR)/libft -I./includes

SRCS = \
./srcs/deque_oper.c \
./srcs/deque.c \
./srcs/devide_cases.c \
./srcs/devide.c \
./srcs/main.c \
./srcs/merge.c \
./srcs/oper.c \
./srcs/oper2.c \
./srcs/oper3.c \
./srcs/pattern.c \
./srcs/utils.c \
./srcs/cases.c \
./srcs/others.c \
./srcs/utils2.c

INC = ./includes/push_swap.h

OBJS = $(SRCS:.c=.o)

all: $(LIB) $(TARGET)

$(LIB):
	make -C $(LIB_DIR)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ $(LIB_DIR)/lib$(LIB).a

%.o: %.c
	$(CC) $(CFLAGS) $< -o ${<:.c=.o} $(INCLUDE)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re