# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francoma <francoma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 09:50:51 by francoma          #+#    #+#              #
#    Updated: 2022/12/11 11:47:26 by francoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
INCLUDE_DIR = includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

SRC_FILES = ft_atoi.c \
	ft_dict_validation.c \
	ft_file_manip.c \
	ft_memory.c \
	ft_parse_dict.c \
	ft_prints.c \
	ft_solve.c \
	ft_solve_fr.c \
	main.c \
	util.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR),$(SRC_FILES))
OBJS = $(addprefix $(SRCS_DIR),$(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
