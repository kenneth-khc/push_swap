CC = cc
CFLAGS = -Wall -Wextra -Werror
RED = \033[0;91m
GREEN = \033[92m
RESET = \033[0m
FSAN = -fsanitize=address -g3

NAME = push_swap
BONUS_NAME = checker
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SOURCES = push_swap.c arguments.c errors.c operations.c operations2.c sorting.c utils.c testing.c stack.c quicksort.c

SOURCES_BONUS = checker.c stack.c utils.c arguments.c errors.c operations.c operations2.c testing.c quicksort.c sorting.c

ARG =

all: $(NAME)

bonus: all

$(NAME): $(LIBFT)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) cleaned!$(RESET)"

re: fclean all

a: $(LIBFT)
	@$(CC) $(SOURCES) $(CFLAGS) $(LIBFT) -o $(NAME) $(FSAN)
	@echo "$(GREEN)test compiled!$(RESET)"
	@./$(NAME) $(ARG) 2>&1 | cat -e
	@echo "$(GREEN)test done!$(RESET)"

b: $(LIBFT)
	@$(CC) $(SOURCES_BONUS) $(CFLAGS) $(LIBFT) -o $(BONUS_NAME) $(FSAN)
	@echo "$(GREEN)checker compiled!$(RESET)"
	@./$(BONUS_NAME) $(ARG) 2>&1 | cat -e
	@echo "$(GREEN"checker done!$RESET)"

.PHONY: all clean fclean re bonus