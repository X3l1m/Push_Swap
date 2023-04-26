NAME = push_swap
ARCHIVE_LIB = libft/libft.a

SRC_DIR = src/

RM = rm -f

SRC 	= $(wildcard $(SRC_DIR)*.c)

all: $(NAME)


$(NAME): $(ARCHIVE_LIB)
	gcc $(SRC) $< -o $@

$(ARCHIVE_LIB):
	make -C libft

clean:
	make -C libft clean

fclean:
	make -C libft fclean && $(RM) push_swap

re: fclean all