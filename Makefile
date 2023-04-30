NAME	= push_swap
LIB		= libft/libft.a

SRC_DIR = src/
GCC		= gcc -Wall -Werror -Wextra
RM		= rm -f

SRC 	= $(wildcard $(SRC_DIR)*.c)

all: $(NAME)


$(NAME): $(LIB)
	$(GCC) $(SRC) $< -o $@

$(LIB):
	make -C libft

clean:
	make -C libft clean

fclean:
	make -C libft fclean && $(RM) $(NAME)

re: fclean all

.PHONY:	$(NAME)