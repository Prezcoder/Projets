# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 08:41:30 by fbouchar          #+#    #+#              #
#    Updated: 2023/01/23 09:40:24 by fbouchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		ft_util.c \
		ft_util2.c \
	
OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME) $(SRCS)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
		
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re