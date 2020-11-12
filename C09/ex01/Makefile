# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 17:34:14 by grusso            #+#    #+#              #
#    Updated: 2020/11/09 17:34:17 by grusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

SRCDIR = srcs
INCDIR = includes

TARGET = libft.a
SOURCES = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDIR)
	
$(TARGET): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
