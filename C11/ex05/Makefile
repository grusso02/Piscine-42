# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 18:42:52 by grusso            #+#    #+#              #
#    Updated: 2020/11/12 11:21:45 by grusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${wildcard ./*.c}
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= do-op

.c.o :	
			${CC} -I ${CFLAGS} -c $< -o ${<:.c=.o}
all :		${OBJS}
			${CC} -o ${NAME} ${OBJS}
clean :
			rm -f ${OBJS}
fclean :	clean
			rm -f ${NAME}
re :		fclean all
