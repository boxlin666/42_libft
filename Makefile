# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Directories
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
INC_DIR = .

# Files
NAME = libft.a
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
TEST_SRC = $(TEST_DIR)/test1.c
TEST_EXEC = test_exec

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(COVFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


# Clean up object files and coverage data
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME) $(TEST_EXEC)
	rm -rf $(COV_DIR)

# Rebuild the library
re: fclean all

# Compile and run tests
test: $(NAME)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(TEST_SRC) $(SRC_FILES) -o $(TEST_EXEC) -lcriterion
	@echo "Running tests ..."
	./$(TEST_EXEC)


.PHONY: all clean fclean re test