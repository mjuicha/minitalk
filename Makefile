PRINTF = ft_printf/libftprintf.a

HEADER = minitalk.h

SERVER = server
CLIENT = client

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

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(PRINTF) $(SERVER) $(CLIENT)

$(SERVER): $(OBJSERVER) $(OBJ)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJSERVER) -o $(SERVER)

$(CLIENT): $(OBJCLIENT) $(OBJ)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJCLIENT) $(OBJ) -o $(CLIENT)

$(SERVERBONUS): $(OBJSERVERBONUS) $(OBJ)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJSERVERBONUS) -o $(SERVER)

$(CLIENTBONUS): $(OBJCLIENTBONUS)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJCLIENTBONUS) -o $(CLIENT)

$(PRINTF):
	@$(MAKE) -C ft_printf
	
bonus: $(PRINTF) $(SERVERBONUS) $(CLIENTBONUS)


clean:	
	rm -f $(OBJSERVER) $(OBJCLIENT) $(OBJ) $(OBJSERVERBONUS) $(OBJCLIENTBONUS)
	@$(MAKE) clean -C ft_printf

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVERBONUS) $(CLIENTBONUS)
	@$(MAKE) fclean -C ft_printf

re: fclean all