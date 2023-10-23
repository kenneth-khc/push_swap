CC = cc
CFLAGS = -Wall -Wextra -Werror
RED = \033[0;91m
GREEN = \033[92m
RESET = \033[0m

INCLUDE_DIR = includes
SOURCES_DIR = sources
OBJECTS_DIR = objects
FT_PRINTF_DIR = $(SOURCES_DIR)/ft_printf
FT_DPRINTF_DIR = $(SOURCES_DIR)/ft_dprintf

LIBFT_SOURCES = $(wildcard $(SOURCES_DIR)/*.c)
LIBFT_OBJECTS = $(patsubst $(SOURCES_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(LIBFT_SOURCES))
FT_PRINTF_SOURCES = $(wildcard $(FT_PRINTF_DIR)/*.c)
FT_PRINTF_OBJECTS = $(patsubst $(FT_PRINTF_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(FT_PRINTF_SOURCES))
FT_DPRINTF_SOURCES = $(wildcard $(FT_DPRINTF_DIR)/*.c)
FT_DPRINTF_OBJECTS = $(patsubst $(FT_DPRINTF_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(FT_DPRINTF_SOURCES))

LIBFT = libft.a

all: $(OBJECTS_DIR) $(LIBFT)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(LIBFT): $(LIBFT_OBJECTS) $(FT_PRINTF_OBJECTS) $(FT_DPRINTF_OBJECTS)
	@ar rcs $(LIBFT) $(LIBFT_OBJECTS) $(FT_PRINTF_OBJECTS) $(FT_DPRINTF_OBJECTS)
	@echo "$(GREEN)libft compiled!$(RESET)"

$(LIBFT_OBJECTS): $(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(FT_PRINTF_OBJECTS): $(OBJECTS_DIR)/%.o: $(FT_PRINTF_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(FT_DPRINTF_OBJECTS): $(OBJECTS_DIR)/%.o: $(FT_DPRINTF_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJECTS_DIR)
	@echo "$(RED)libft objects cleaned!$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)libft cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re