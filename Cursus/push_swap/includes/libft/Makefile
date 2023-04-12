# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 07:46:56 by fbouchar          #+#    #+#              #
#    Updated: 2023/04/12 09:42:35 by fbouchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
O = obj/
SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		get_next_line.c \
		malloc_join.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_printf.c \
		ft_util2.c \
		ft_util.c \
		

	
OBJS = $(SRCS:%.c=%.o)
OBJS := $(OBJS:%=$O%)



CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME) $(SRCS)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)

$O%.o:%.c
	@mkdir -p $O
	@$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	@rm -rf $O

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

.PHONY: all clean fclean re