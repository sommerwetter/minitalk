# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 22:07:12 by marmoral          #+#    #+#              #
#    Updated: 2022/06/04 13:16:50 by marmoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

FLAGS =	-Wall -Wextra -Werror

FILES =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c	ft_putstr_fd.c ft_split.c ft_strchr.c\
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\

OBJ = ${FILES:.c=.o}

RM = rm -f

CC = gcc

all: $(NAME)

$(NAME) : ${OBJ}
	ar rcs $(NAME) ${OBJ}

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} $(NAME) 

re: fclean all

.PHONY: all clean fclean re