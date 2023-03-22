CFLAGS	:= -Wextra -Wall -Werror
CC := gcc
SRCS_CLIENT :=./src_client/client.c \
				./src_client/ft_atoi.c \

OBJS_CLIENT := ${SRCS_CLIENT:.c=.o}
SRCS_SERVER :=./src_server/server.c \
				./src_server/ft_putnbr_fd.c \
				./src_server/ft_putchar_fd.c \
				./src_server/ft_putstr_fd.c \

OBJS_SERVER := ${SRCS_SERVER:.c=.o}	
OBJS	:= ${SRCS:.c=.o}

all: server client

client: $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -o client

server: $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) -o server

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)"

debug: $(NAME)
	@$(CC) -g $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVEUR)
	
fclean: clean
	@rm -f client
	@rm -f server

re: fclean all

.PHONY: all clean fclean re