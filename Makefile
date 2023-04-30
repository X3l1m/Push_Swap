# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: seyildir <seyildir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/30 04:52:46 by seyildir      #+#    #+#                  #
#    Updated: 2023/04/30 06:30:13 by seyildir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard src/*.c utils/*.c)
OBJS = ${SRCS:.c=.o}

CC = gcc -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJS) ./libft/libft.a -o $(NAME)

clean: 
	@$(MAKE) -C ./libft fclean
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Siyah: \033[0;30m veya \033[30m
# Kırmızı: \033[0;31m veya \033[31m
# Yeşil: \033[0;32m veya \033[32m
# Sarı: \033[0;33m veya \033[33m
# Mavi: \033[0;34m veya \033[34m
# Magenta: \033[0;35m veya \033[35m
# Cyan: \033[0;36m veya \033[36m
# Beyaz: \033[0;37m veya \033[37m
# Bold: \033[1m
# Altı çizili: \033[4m
# Ters: \033[7m
# Sıfırlama: \033[0m