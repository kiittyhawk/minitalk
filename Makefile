INCLUDE = -I./includes

NAME = minitalk

SERVER = server

CLIENT = client

FTFLAGS= -Llibft -lft

GCC = clang

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all : $(NAME) 

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : srcs/server.o includes/minitalk.h
	make -C ./libft
	$(GCC) srcs/server.o $(CFLAGS) $(FTFLAGS) -o $(SERVER) 
	
$(CLIENT) : srcs/client.o includes/minitalk.h
	$(GCC) srcs/client.o $(CFLAGS) $(FTFLAGS) -o $(CLIENT) 

%.o : %.c
	$(GCC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean : 
	$(RM) srcs/client.o srcs/server.o

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	make clean -C ./libft

re: fclean all

.PHONY: all clean fclean re
