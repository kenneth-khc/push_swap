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
SOURCES = push_swap.c arguments.c errors.c \
operations.c operations2.c sorting.c sections.c \
utils.c testing.c stack.c quicksort.c sort_a.c sort_a_utils.c sort_b.c sort_b_utils.c \
divide_and_conquer.c

SOURCES_BONUS = checker.c stack.c utils.c arguments.c errors.c operations.c operations2.c testing.c quicksort.c sorting.c

ARG =

all: $(NAME)

bonus: all

$(NAME): $(LIBFT)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBFT) -o $(NAME) -g
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
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"
	@./$(NAME) "12 15 0 13 10 1 19 18 9 5 14 3 8 6 17 7 11 4 16 2" 2>&1 | cat -e
#@./$(NAME) "11 20 8 18 15 19 16 17 5 6 3 4 1 13 10 2 7 12 14 9" 2>&1 | cat -e
#@./$(NAME) "6 12 20 1 3 11 10 21 23 8 18 16 24 2 13 5 9 22 15 7 17 4 14 0 19" 2>&1 | cat -e
#@./$(NAME) "8 80 97 55 28 63 43 53 33 36 25 31 82 90 44 19 84 89 94 32 96 78 67 2 11 7 30 26 14 65 64 70 27 24 38 57 49 4 76 3 10 59 69 77 93 21 74 17 71 12 73 13 45 52 54 5 23 61 66 72 1 87 47 18 48 34 39 0 98 35 92 68 29 6 51 50 85 91 58 56 9 88 86 83 37 42 46 40 62 41 95 81 15 75 20 22 99 16 79 60"

b: $(LIBFT)
	@$(CC) $(SOURCES_BONUS) $(CFLAGS) $(LIBFT) -o $(BONUS_NAME) $(FSAN)
	@echo "$(GREEN)checker compiled!$(RESET)"
	@./$(BONUS_NAME) $(ARG) 2>&1 | cat -e
	@echo "$(GREEN"checker done!$RESET)"

.PHONY: all clean fclean re bonus