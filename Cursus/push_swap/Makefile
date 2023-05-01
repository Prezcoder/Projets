NAME = push_swap
CFLAGS = -Wextra -Wall -Werror -g -O0
CC := gcc
S = ./src/
O = ./obj/
LIBFT = ./includes/libft/libft.a
SRC = 	push_swap.c \
		ft_parsing.c \
		ft_make_list.c \
		ft_instruct.c \
		ft_algo.c \
		ft_actions.c \

OBJ = $(SRC:%.c=%.o)
OBJ := $(OBJ:%=$O%)

RM = rm -rf

$O%.o:$S%.c
	@mkdir -p $O
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ./includes/libft
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

clean:
	@$(MAKE) clean -C ./includes/libft
	@$(RM) $O

fclean: clean
	@$(MAKE) fclean -C ./includes/libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re