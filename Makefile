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

# 分类文件
MAN_SRC_FILES = $(filter-out $(SRC_DIR)/ft_lst%.c, $(SRC_FILES))
BONUS_SRC_FILES = $(filter $(SRC_DIR)/ft_lst%.c, $(SRC_FILES))

# 对应目标文件
MAN_OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(MAN_SRC_FILES))
BONUS_OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRC_FILES))

# 所有目标文件
OBJ_FILES = $(MAN_OBJ_FILES) $(BONUS_OBJ_FILES)

TEST_SRC = $(TEST_DIR)/new_test.c
TEST_EXEC = test_exec

# 默认目标
all: $(NAME)

# 创建静态库
$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# man 目标：只编译非 ft_lst 文件
man: $(MAN_OBJ_FILES)
	ar rcs $(NAME) $(MAN_OBJ_FILES)

# bonus 目标：只编译 ft_lst 文件
bonus: $(BONUS_OBJ_FILES)
	ar rcs $(NAME) $(BONUS_OBJ_FILES)

# 编译 .c -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 创建 obj 目录
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 清除对象文件
clean:
	rm -rf $(OBJ_DIR)

# 清除所有生成文件
fclean: clean
	rm -f $(NAME) $(TEST_EXEC)
	rm -rf $(COV_DIR)

# 重建
re: fclean all

# 测试目标
test: $(NAME)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(TEST_SRC) $(SRC_FILES) -o $(TEST_EXEC) -lcriterion
	@echo "Running tests ..."
	./$(TEST_EXEC)

.PHONY: all clean fclean re test man bonus
