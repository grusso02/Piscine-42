# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 19:06:15 by grusso            #+#    #+#              #
#    Updated: 2020/11/10 14:29:29 by grusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
TARGET = ft_cat
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
