# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: seyildir <seyildir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/30 04:52:46 by seyildir      #+#    #+#                  #
#    Updated: 2023/04/30 04:54:47 by seyildir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN=\033[32m
RED=\033[31m
NC=\033[0m

NAME	= push_swap
LIB		= libft/libft.a
LIBS	 = -L ./libft -lft

SRC_DIR = ./src
OBJ_DIR = ./obj
GCC		= gcc -Wall -Werror -Wextra
RM		= rm -f

SRC 	= $(wildcard $(SRC_DIR)/*.c)
OBJ		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(LIB) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(GCC) -c $< -o $@
	@echo "$(GREEN)Compiling $(RED)$(basename $(notdir $<))$(NC)"

$(NAME): $(OBJ)
	$(GCC) $(LIBS) $^ -o $@
	@echo "Creating $(NAME)"
$(LIB):
	make -C libft

clean:
	make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libft fclean && $(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re

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