# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 15:17:48 by jgyles            #+#    #+#              #
#    Updated: 2021/10/11 15:17:49 by jgyles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = -I./includes

NAME = minitalk

SERVER = server

CLIENT = client

FTFLAGS= -Llibft -lft

GCC = clang

RM = rm -f

CFLAGS = -g -Wall -Werror -Wextra

all : $(NAME) 

$(NAME) : $(SERVER) $(CLIENT)
			@echo "\033[32m   DONE \033[0m"

$(SERVER) : srcs/server.o includes/minitalk.h includes/libft.h
	@make -C ./libft
	@$(GCC) srcs/server.o $(CFLAGS) $(FTFLAGS) -o $(SERVER) 
	
$(CLIENT) : srcs/client.o includes/minitalk.h includes/libft.h
	@$(GCC) srcs/client.o $(CFLAGS) $(FTFLAGS) -o $(CLIENT) 

%.o : %.c
	@$(GCC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@echo "\033[35m   Compiling...  $<\033[0m"

clean : 
	@$(RM) srcs/client.o srcs/server.o
	@echo "\033[32m------> CLEAN  completed <------\033[0m"

fclean: clean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)
	@make fclean -C ./libft
	@echo "\033[32m------> FCLEAN completed <------\033[0m"

re: fclean all
	@echo "\033[36m------>   RE completed   <------\033[0m"

.PHONY: all clean fclean re
