NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
SRCS	:=./src/ft_parsing.c \
			./src/main.c \
			./src/ft_parsing2.c \
			./src/make_map.c \
			
OBJS	:= ${SRCS:.c=.o}
LIBFT	:= ./libft/libft.a

all: libmlx $(NAME)

run : all
	./so_long ./map/map.ber

libmlx: 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)

debug: $(NAME)
	@$(CC) -g $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build
	
fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx