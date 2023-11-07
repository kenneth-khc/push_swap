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
SOURCES = push_swap.c arguments.c errors.c \
operations_swap_push.c operations_rotate.c operations_reverse_rotate.c \
sorting.c sections.c stack.c stack_utils.c stack_utils2.c stack_utils3.c \
quicksort.c sort_a.c sort_a_utils.c sort_b.c sort_b_utils.c \
divide_section.c solve_a.c optimize_swaps.c optimize_rotates.c test.c

CHECKER_DIR = checker_src
SOURCES_BONUS = $(CHECKER_DIR)/checker.c $(CHECKER_DIR)/checker_utils.c stack.c stack_utils.c arguments.c \
errors.c $(CHECKER_DIR)/checker_operations.c $(CHECKER_DIR)/checker_operations2.c $(CHECKER_DIR)/checker_operations3.c \
quicksort.c sorting.c sort_a_utils.c stack_utils2.c optimize_swaps.c

ARG = 1 2 3

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBFT) -g -o $(NAME)
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

re: fclean all

a: $(LIBFT)
	@$(CC) $(SOURCES) $(CFLAGS) $(LIBFT) -o $(NAME) $(FSAN)
#	@echo "$(GREEN)$(NAME) compiled!$(RESET)"
#	@./$(NAME) "1 20 90 23 45 48 19 50 4 17 16 91 56 12 10 13 61 46 25 22 52 14 86 60 66 79 7 44 30 2 83 75 70 63 74 53 65 49 40 42 33 32 71 28 81 43 59 34 37 11 68 73 99 26 41 35 5 55 78 62 27 89 77 29 82 8 9 84 95 93 24 38 85 88 58 47 64 3 36 39 87 80 31 0 98 96 76 6 97 92 18 72 94 67 51 15 21 69 57 54"
#	@./$(NAME) "12 15 0 13 10 1 19 18 9 5 14 3 8 6 17 7 11 4 16 2" 2>&1 | cat -e
##	@./$(NAME) "11 20 8 18 15 19 16 17 5 6 3 4 1 13 10 2 7 12 14 9" 2>&1 | cat -e
#	@./$(NAME) "6 12 20 1 3 11 10 21 23 8 18 16 24 2 13 5 9 22 15 7 17 4 14 0 19" 2>&1 | cat -e
#	@./$(NAME) "8 80 97 55 28 63 43 53 33 36 25 31 82 90 44 19 84 89 94 32 96 78 67 2 11 7 30 26 14 65 64 70 27 24 38 57 49 4 76 3 10 59 69 77 93 21 74 17 71 12 73 13 45 52 54 5 23 61 66 72 1 87 47 18 48 34 39 0 98 35 92 68 29 6 51 50 85 91 58 56 9 88 86 83 37 42 46 40 62 41 95 81 15 75 20 22 99 16 79 60"
# 500
#	@./$(NAME) "-316 7037 -9745 198 -6599 7669 -6433 2386 2188 7020 -4051 7399 -9313 -9300 -6593 -2221 -4844 -6134 8226 9354 6531 -3924 7895 8187 -7141 -2320 -2444 2692 -2235 -7884 -4497 -9814 -6530 6006 8472 -8583 942 -893 -7385 -2889 -5927 601 -7660 -8126 -2883 -7720 6830 8455 -9030 -8958 3561 1194 7531 -2802 -8270 1557 -247 -8045 -8896 -3567 7567 7917 7742 6409 -872 9929 -5960 -1385 -2647 9472 9272 6901 2175 -7631 3907 -323 4960 -5234 3259 -5452 8125 9632 -5698 5666 699 -8733 -3768 6397 -7538 5589 6701 -1471 9450 9867 -2606 8209 9118 7398 6134 3120 -8356 9306 8433 -6259 8062 -2040 9805 7121 192 -6520 8200 2193 -5980 -1412 2072 876 212 -4188 2903 6625 -1427 -9953 -5983 150 -4973 -7771 -3113 -9515 -8127 -1149 7480 1885 -804 -5244 5041 1969 -8840 -487 -9875 -8010 5379 7674 -4018 -8267 -1290 -2332 -6000 -7435 -6940 -9290 9181 1985 4054 -994 1958 5236 705 7775 8707 -6841 2664 -8604 -1437 -5504 -2787 -8802 9527 7819 3368 -8608 -9554 1451 4242 -9475 -8362 1087 7556 765 -4387 4166 5023 -3635 7778 4990 5829 3413 -2798 -847 7570 -4305 -7814 3645 -4766 2030 8359 5617 -9145 4718 3169 3725 -9429 -7677 -9659 -1959 -5319 3288 3007 2397 3829 5744 -4564 4625 2561 7378 -8099 -4490 5809 -8103 2303 -3824 8635 -8537 -5064 -1532 5726 -1206 -6601 -9975 -839 3903 -4580 5846 1864 -1679 -8441 -6852 8563 -9833 -2020 -3867 -4238 -8044 4309 -5182 4807 6424 -2247 5351 -7644 -2354 4967 3555 -2590 3611 1738 -9248 2071 -1376 -1322 376 113 -7129 -5749 3031 276 -414 -8324 -303 -3520 6192 1656 6807 9476 -3352 2318 3190 -4476 -7673 9057 -3002 6715 1 -9487 -4937 3372 1518 7433 8657 -1074 7858 2525 -1683 -2373 1374 -5159 1750 7789 1514 -1722 -7309 1045 4678 -9196 9708 -6095 -741 2244 1177 -4688 6237 -1680 -5542 -5913 -4436 6844 -2388 -3186 -8385 6885 4509 370 -2739 -3641 6400 5052 6166 4744 -6167 8280 7386 -7852 -6882 4931 9139 7684 6135 -7298 9144 -7207 -5019 -675 -3857 4648 -1183 -4622 -4370 1949 -1630 193 9722 1138 -6673 6028 -78 182 -4899 2105 8068 -7035 4061 5773 -3226 -2773 -2163 -8241 -4344 -9546 -8768 5401 1288 7623 -4908 -8781 -9143 8348 -8547 -318 -7885 500 -1174 -8900 2786 3511 -343 -7640 6801 -2403 423 -6141 7937 -9281 6723 -7425 5042 -8515 -8862 7660 -1058 -6333 -4665 2785 2220 -6609 1666 4842 1425 4113 708 -417 4782 6611 -5701 -3558 -5474 -6264 4767 3527 136 9935 7757 -6126 -7530 -9068 4723 7521 -2699 -97 6301 -6699 -251 3780 9633 -2107 -5124 -4969 1505 -845 -413 1790 -7744 -3178 -686 4099 -2227 -3049 2740 -1161 6089 9084 -859 -6522 -2231 3273 -9140 -3591 -1550 -1243 -7306 -5137 -8187 -8667 7130 7295 -7998 3415 2442 915 7626 -4445 -6331 1020 -1375 -7988 -8760 -4681 -6866 3622 4249 418 7325 2332 6865 -3739 -6306 -6497 4938 3289 1756 8081 -639 8235 -6073 5335 489 3241 -870 -8332 2672 8687 -694"
# 100
	@./$(NAME) "4790 -3908 7767 -1664 1758 2061 3502 -9600 -8182 -6295 -3851 -2019 2587 -9266 6451 3380 -3281 9668 2077 2422 -9052 -9205 7009 -6334 5489 -7957 5290 4339 -5106 6655 -8069 -7150 -5388 -5710 -6164 -3690 9311 -8431 3958 3056 -6622 -454 -8035 9919 8442 -3855 3118 3605 5044 -9950 -6584 -3399 7492 6608 -8903 9910 8512 -2601 -9503 -9440 -6446 7558 -6036 9898 6227 -1657 -8422 -4498 3391 5469 -7046 -5685 1797 5307 994 -1375 3061 -4929 3041 9098 -8363 -3779 1263 -5266 -1950 -2320 5077 -5041 -5977 934 4932 -7903 -5695 -4554 -7532 3575 1534 4676 -9365 -1817"
# 50
#	@./$(NAME) "-9133 -8054 5571 -3495 -2539 3738 -4379 -6803 -3944 -71 7047 8763 3593 -60 -7233 9098 -879 -4901 -188 -8662 -714 -7088 -7989 -890 9956 1036 -9340 -8022 1855 -5973 8969 9309 -1666 5948 -8548 6390 4446 -8912 4477 5509 -9425 -2653 -228 -5234 -8842 6444 2499 -2568 3305 -8164"
# 25
#	@./$(NAME) "8347 -4500 -5525 5157 2385 -4765 8844 8549 -9229 4037 -8780 -1978 9452 9737 9878 4815 -5127 -6435 5831 5895 -551 -5089 3519 -8766 5362"
# 10
#	@./$(NAME) "3259 6890 -2864 859 -944 -445 7161 -2144 -3313 -1734"

b: $(LIBFT)
	@$(CC) $(SOURCES_BONUS) $(CFLAGS) $(LIBFT) -o $(BONUS_NAME) $(FSAN)
	@echo "$(GREEN)checker compiled!$(RESET)"
	@./$(BONUS_NAME) $(ARG)
	@echo "$(GREEN"checker done!$RESET)"

.PHONY: all clean fclean re bonus