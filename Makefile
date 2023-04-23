NAME = push_swap
HEADER = push_swap.h

SRC_DIR = src/

SRC 	= $(wildcard $(SRC_DIR)/*.c)
OBJ		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
