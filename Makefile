PRINTF = ft_printf/libftprintf.a

HEADER = minitalk.h
HEADERBONUS = minitalk_bonus.h
HEADERPRINTF = ft_printf/ft_printf.h

SERVER = server
CLIENT = client

SERVERBONUS = server_bonus
CLIENTBONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = utils.c

SRCSSERVER = server.c
SRCSCLIENT = client.c

SRCSSERVERBONUS = server_bonus.c
SRCSCLIENTBONUS = client_bonus.c

OBJ = $(SRCS:.c=.o)

OBJSERVER = $(SRCSSERVER:.c=.o)
OBJCLIENT = $(SRCSCLIENT:.c=.o)

OBJSERVERBONUS = $(SRCSSERVERBONUS:.c=.o)
OBJCLIENTBONUS = $(SRCSCLIENTBONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(PRINTF) $(SERVER) $(CLIENT)

$(SERVER): $(OBJSERVER) $(HEADER)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJSERVER) -o $(SERVER)

$(CLIENT): $(OBJCLIENT) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJCLIENT) $(OBJ) -o $(CLIENT)

$(SERVERBONUS): $(OBJSERVERBONUS) $(HEADERBONUS)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJSERVERBONUS) -o $(SERVERBONUS)

$(CLIENTBONUS): $(OBJCLIENTBONUS) $(OBJ) $(HEADERBONUS)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJCLIENTBONUS) $(OBJ) -o $(CLIENTBONUS)

$(PRINTF): $(HEADERPRINTF) ft_printf/*.c
	@$(MAKE) -C ft_printf
	
bonus: $(PRINTF) $(SERVERBONUS) $(CLIENTBONUS)

clean:	
	rm -f $(OBJSERVER) $(OBJCLIENT) $(OBJ) $(OBJSERVERBONUS) $(OBJCLIENTBONUS)
	@$(MAKE) clean -C ft_printf

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVERBONUS) $(CLIENTBONUS)
	@$(MAKE) fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re bonus