# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 21:23:46 by slyu              #+#    #+#              #
#    Updated: 2021/09/29 21:29:29 by slyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ./srcs/main.c ./srcs/file_io.c ./srcs/error.c ./srcs/make_int_map.c ./srcs/file_etc.c ./srcs/file_read.c ./srcs/find_biggest.c ./srcs/is_able.c ./srcs/map_error.c ./srcs/map_free.c ./srcs/map_init.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = bsq
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

run :
	./${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all run clean fclean re
