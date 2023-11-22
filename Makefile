CC = cc
CFLAGS = -Wall -Wextra -Werror
FSAN =
RED = \033[0;91m
GREEN = \033[92m
RESET = \033[0m

NAME = push_swap
BONUS_NAME = checker
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SOURCES = push_swap.c arguments.c init_stack.c \
stack_utils.c stack_utils2.c \
sections.c sections_utils.c first_section.c first_section_utils.c \
operations_swap_push.c operations_rotate.c operations_reverse_rotate.c \
optimize_swaps.c optimize_rotates.c \
quicksort.c sort_a.c sort_a_utils.c divide_section_a.c \
divide_section_b.c solve_a.c sort_sections.c

CHECKER_DIR = checker_src
SOURCES_BONUS = $(CHECKER_DIR)/checker.c $(CHECKER_DIR)/checker_utils.c init_stack.c stack_utils.c arguments.c quicksort.c \
$(CHECKER_DIR)/checker_op_swap_push.c $(CHECKER_DIR)/checker_op_rotate.c $(CHECKER_DIR)/checker_op_reverse_rotate.c \

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBFT) -o $(NAME) -g
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(BONUS_NAME): $(LIBFT)
	$(CC) $(SOURCES_BONUS) $(CFLAGS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(GREEN)$(BONUS_NAME) compiled!$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(RED)$(NAME) cleaned!$(RESET)"
	@echo "$(RED)$(BONUS_NAME) cleaned!$(RESET)"

re: fclean all bonus

.PHONY: all clean fclean re bonus