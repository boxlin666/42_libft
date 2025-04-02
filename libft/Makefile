# Makefile for libft project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# The name of the output library
NAME = libft.a

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = .

# Source files and object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Create the library
$(NAME): $(OBJ_FILES)
	@echo "Creating $(NAME)..."
	ar rcs $(NAME) $(OBJ_FILES)
	@echo "$(NAME) created successfully."

# Compile the source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Ensure obj directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean up object files
clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJ_DIR)

# Clean everything (objects and the library)
fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)

# Rebuild the library
re: fclean $(NAME)

# Run the tests
TEST = tests/test.c
TEST_EXEC = test

test: $(NAME)
	@echo "Compiling test cases..."
	$(CC) $(CFLAGS) -I $(INC_DIR) $(TEST) -L. -lft -lcriterion -o $(TEST_EXEC)
	@echo "Running tests..."
	./$(TEST_EXEC)

.PHONY: all clean fclean re test
