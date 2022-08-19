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

CC = cc
CFLAGS = -Wall -Wextra -Werror -c -g
FLAGS = -Wall -Wextra -Werror -g
TARGET = push_swap
CHECKER = checker
LIB_DIR = ./ft_printf
LIB = ftprintf
INCLUDE = -I$(LIB_DIR)/includes -I$(LIB_DIR)/libft -I./includes
DEFINE = -D BUFFER_SIZE=1000

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

GNL_SRCS = \
./srcs/get_next_line.c \
./srcs/get_next_line_utils.c

CHECKER_SRCS = \
./srcs/deque_oper.c \
./srcs/deque.c \
./srcs/oper.c \
./srcs/oper2.c \
./srcs/oper3.c \
./srcs/utils.c \
./srcs/others.c \
./srcs/utils2.c \
./srcs/checker.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(LIB) $(TARGET)

$(LIB):
	make -C $(LIB_DIR)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ $(LIB_DIR)/lib$(LIB).a

bonus: $(LIB) $(CHECKER)

$(CHECKER): $(CHECKER_OBJS) $(GNL_OBJS)
	$(CC) $(FLAGS) -o $@ $^ $(LIB_DIR)/lib$(LIB).a

%.o: %.c
	$(CC) $(CFLAGS) $< -o ${<:.c=.o} $(INCLUDE) $(DEFINE)

clean:
	make clean -C $(LIB_DIR) 
	rm -f $(OBJS) $(CHECKER_OBJS) $(GNL_OBJS)

fclean:
	make fclean -C $(LIB_DIR) 
	rm -f $(OBJS) $(CHECKER_OBJS) $(GNL_OBJS)
	rm -f $(TARGET) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re