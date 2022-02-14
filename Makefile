# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 21:38:04 by slyu              #+#    #+#              #
#    Updated: 2022/02/14 20:01:30 by slyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a
INCLUDE = -I$(LIB_DIR) -I./includes

SRCS = \
srcs/ft_printf.c \
srcs/complete_str.c	\
srcs/flags.c \
srcs/itoa.c \
srcs/itoa_16.c \
srcs/others.c \
srcs/print.c \
srcs/utils.c \
srcs/write.c

BONUS_SRCS = \
bonus/ft_printf_bonus.c \
bonus/complete_str_bonus.c	\
bonus/flags_bonus.c \
bonus/itoa_bonus.c \
bonus/itoa_16_bonus.c \
bonus/others_bonus.c \
bonus/print_bonus.c \
bonus/utils_bonus.c \
bonus/write_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR) all
	cp $(LIB) $(NAME)
	ar rcs $@ $^

bonus: $(BONUS_OBJS)
	make -C $(LIB_DIR) all
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) $< -o ${<:.c=.o} $(INCLUDE)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
