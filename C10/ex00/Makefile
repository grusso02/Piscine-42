# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 18:39:44 by grusso            #+#    #+#              #
#    Updated: 2020/11/10 12:05:43 by grusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

TARGET = ft_display_file
SOURCES = ft_display_file.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	gcc $(CFLAGS) -c $<

$(TARGET): $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
