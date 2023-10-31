/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 23:57:22 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

enum e_directions {
	UP = 'U',
	DOWN = 'D'
};

typedef struct s_stack				t_stack;
typedef struct s_node				t_node;
typedef struct s_section_list		t_section_list;
typedef struct s_section			t_section;

struct s_stack
{
	t_node	*top;
};

struct s_node
{
	int		data;
	int		id;
	t_node	*next;
};

struct s_section_list
{
	t_section	*head;
	t_section	*tail;
};

struct s_section
{
	int			len;
	char		in;
	t_section	*prev;
	t_section	*next;
};

/* Arguments */
int		*parse_arguments(int argc, char **argv, int *size);
char	*join_arguments(char *s1, const char *s2);
char	**extract_arguments(char **argv);
int		count_numbers(char **strings);
void	validate_integers(int *integer_arr, char **argv);
void	check_for_duplicates(int *array, int size);
void	init_stacks(t_stack *a, t_stack *b, int *integer_arr, int size);
void	simplify_stack(int *array, t_stack *a);

/* Real quicksort */
void	quick_sort(int *array, int size);
void	quick_sort_recurse(int *array, int start_index, int end_index);
int		partition(int *array, int start_index, int end_index);
void	swap(int *x, int *y);

/* Operations */
void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Sorting stack A */
void	quicksort(t_stack *a, t_stack *b, int size);
int		push_half_to_b(t_stack *a, t_stack *b, t_section_list *sections);
void	sort_a(t_stack *a, t_stack *b,
			int num_of_elements, t_section_list *list);
void	push_to_b(int to_push, int mid, t_stack *a, t_stack *b);
void	sort_three(t_stack *a, t_stack *b);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_section_a(t_stack *a, t_stack *b, int section_len);
//
void	push_section_to_a(int to_push, int mid, t_stack *a,
			t_stack *b);
int		find_nums_to_push_b(int mid, t_stack *stack, int section_len);
void	pushback_to_b(int to_push, int mid, t_stack *a, t_stack *b);

/* Sort A utils */
int		find_midpoint(t_stack *stack);
int		find_nums_to_push(int mid, t_stack *a);
char	decide_direction_a(t_stack *stack, int midpoint, bool *checked);

/* Sorting stack B */
void	sort_b(t_stack *a, t_stack *b, t_section_list *list);
void	divide_section(t_stack *a, t_stack *b, t_section_list *sections);
int		divide_section_b(t_stack *a, t_stack *b, t_section *section);
void	divide_a_until_sorted(t_stack *a, t_stack *b,
			t_section_list *sections, t_section *latest_a);
void	sort_section_b(t_stack *a, t_stack *b, int section_len);
int		divide_section_a(t_stack *a, t_stack *b, t_section *section);
void	push_last_section(int to_push, int mid, t_stack *a, t_stack *b);

/* Sort B utils */
int		find_mid_in_section(t_stack *stack, int section_len);
char	decide_direction_b(t_stack *stack, int midpoint, bool *checked);

/* Utils */
void	error(void);
void	push(t_stack *stack, int data);
int		stack_len(t_stack *a);
void	shift_stack(t_stack *a, t_stack *b, char direction, char current_stack);
bool	elements_are_ascending(t_stack *stack);
bool	section_is_ascending(t_stack *stack, int len);
bool	section_is_descending(t_stack *stack, int len);
bool	stacks_are_not_sorted(t_stack *a, t_stack *b);
int		find_min(t_stack *a);
void	find_min_max(t_stack *stack, int *min, int *max);
void	find_section_min_max(t_stack *stack, int len, int *min, int *max);
void	free_stacks(t_stack *a, t_stack *b);
bool	top_is_ascending(t_stack *stack);
bool	top_is_descending(t_stack *stack);
void	optimized_swap(char stack, t_stack *a, t_stack *b);
bool	rr_optimizable(t_stack *a, t_stack *b);
bool	rrr_optimizable(t_stack *a, t_stack *b);
void	assign_three_nodes(t_stack *a,
			t_node **first, t_node **second, t_node **third);
void	push_sorted_section(t_stack *a, t_stack *b, int section_len);
void	push_to_opposite_stack(t_stack *a, t_stack *b, char current_stack);

// Sections list
void	add_section(int to_sort, t_section_list *list, char stack);
void	remove_section(t_section_list *sections);

#endif