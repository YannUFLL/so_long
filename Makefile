# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 12:48:02 by ydumaine          #+#    #+#              #
#    Updated: 2022/04/13 01:03:25 by ydumaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c so_long_printmap.c so_long_checkmap.c get_next_line.c\
get_next_line_utils.c

MINILIX = -lmlx -framework OpenGL -framework AppKit -lz

BIBL = libft.a libftprintf.a\

OBJS = ${SRCS:.c=.o}

NAME = so_long

CC = cc

LINK = cc -o

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=10

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${LINK} ${NAME} ${OBJS} ${BIBL} ${MINILIX} 

all:		${NAME}

clean:
			${RM} ${OBJS} ${BOBJS}

fclean:     clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
