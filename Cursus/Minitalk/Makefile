CFLAGS	:= -Wextra -Wall -Werror
CC := gcc
SRCS_CLIENT :=  ./src/client.c \
				./src/minitalk_utils.c \

OBJS_CLIENT := ${SRCS_CLIENT:.c=.o}
SRCS_SERVER :=  ./src/server.c \
				./src/minitalk_utils.c

OBJS_SERVER := ${SRCS_SERVER:.c=.o}	
OBJS	:= ${SRCS_CLIENT:.c=.o} ${SRCS_SERVER:.c=.o}	

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(NAME) :

$(CLIENT): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)"

debug: $(NAME)
	@$(CC) -g $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	
fclean: clean
	@rm -f $(CLIENT)
	@rm -f $(SERVER)

bonus: all

re: fclean all

.PHONY: all clean fclean bonus re