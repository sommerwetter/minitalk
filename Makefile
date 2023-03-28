# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 19:54:14 by marmoral          #+#    #+#              #
#    Updated: 2023/03/27 21:28:01 by marmoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

CC = gcc

LPATH = ./libft

RM = rm -f

all: server client

server: server.c
	make all -C $(LPATH)
	$(CC) $(CFLAGS) server.c $(LPATH)/libft.a -o server

client: client.c
	$(CC) $(CFLAGS) client.c $(LPATH)/libft.a -o client

clean:
	make clean -C libft/
	
fclean: 
	$(RM) server
	$(RM) client
	make fclean -C $(LPATH)

re: fclean all