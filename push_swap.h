/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/21 23:17:08 by kecheong         ###   ########.fr       */
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

typedef struct s_int_array
{
	int	*buf;
	int	size;
}	t_int_array;

typedef struct s_node
{
	int				data;
	int				id;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_section
{
	int					len;
	char				in;
	struct s_section	*prev;
	struct s_section	*next;
}	t_section;

typedef struct s_sections
{
	t_section	*head;
	t_section	*tail;
}	t_sections;

typedef void	(*t_sorter_ptr)(t_stack *, t_stack *);

/* Arguments */
void	parse_arguments(int argc, char **argv, t_int_array *integers);
char	*join_arguments(char *s1, const char *s2);
char	**extract_arguments(char **argv, int *size);
int		count_numbers(char **strings);
void	validate_integers(int *integers, char **argv);
void	check_for_duplicates(t_int_array *array);
void	init_stacks(t_stacks *stacks, t_int_array *int_array);
t_int_array	*process_numbers(t_int_array *int_array);
void	simplify_stack(t_int_array *array, t_stack *a);

/* Real sort */
void	quick_sort(t_int_array *array);
void	quick_sort_recurse(int *array, int start_index, int end_index);
int		partition(int *array, int start_index, int end_index);
void	swap(int *x, int *y);

/* Operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Sorting stack A */
void	sort(t_stacks *stacks, int size);
int		half_a_to_b(t_stacks *stacks, t_sections *sections, int first_mid);
void	sort_a(t_stacks *stacks, t_sections *list);
// void	push_to_b(int to_push, int mid, t_stack *a, t_stack *b);
int		push_to_b(int to_push, int mid,
			t_stack *a, t_stack *b, int first_mid);
void	solve_a(t_stacks *stacks, int len);
void	sort_three(t_stack *a, t_stack *b);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_section_a(t_stack *a, t_stack *b, int section_len);
//
int		push_section_to_a(int to_push, int mid, t_stack *a,
			t_stack *b);
int		count_nums_to_push_b(int mid, t_stack *stack, int section_len);
int		pushback_to_b(int to_push, int mid, t_stack *a, t_stack *b);

/* Sort A utils */
int		find_midpoint(t_stack *stack);
int		count_nums_to_push(t_stack *a, int mid);
char	decide_direction_a(t_stack *stack, int midpoint, bool *checked);

/* Sorting stack B */
void	sort_b(t_stacks *stacks, t_sections *list);
void	divide_section(t_stack *a, t_stack *b, t_sections *sections);
int		divide_section_b(t_stack *a, t_stack *b, t_section *section);
void	divide_a_until_sorted(t_stack *a, t_stack *b,
			t_sections *sections, t_section *latest_a);
void	sort_section_b(t_stack *a, t_stack *b, int section_len);
int		divide_section_a(t_stack *a, t_stack *b, t_section *section);
void	push_last_section(int to_push, int mid, t_stack *a, t_stack *b);

/* Sort B utils */
int		find_section_midpoint(t_stack *stack, int section_len);
char	decide_direction_b(t_stack *stack, int midpoint, bool *checked);

/* Utils */
void	error(void);
void	push(t_stack *stack, int data);
int		stack_len(t_stack *a);
void	shift_stack(char direction, char current_stack, t_stack *a, t_stack *b);
bool	elements_are_ascending(t_stack *stack);
bool	section_is_ascending(t_stack *stack, int len);
bool	section_is_descending(t_stack *stack, int len);
bool	stacks_are_sorted(t_stack *a, t_stack *b);
int		find_min(t_stack *a);
void	find_min_max(t_stack *stack, int *min, int *max);
void	find_section_min_max(t_stack *stack, int len, int *min, int *max);
void	free_stacks(t_stacks *stacks);
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
void	add_section(int to_sort, t_sections *list, char stack);
void	add_unsorted_section(char location, int len, t_sections *sections);
void	remove_last_section(t_sections *sections);

// organize later

int		find_section_minimum(t_stack *stack, int section_len);

bool	last_section_in_b(t_section *current);
void	remove_current_section_a1(t_section *current);
void	update_sections(t_sections *sections, t_stack *a, t_stack *b);
void	remove_current_section_a(t_sections *s, t_section *current);
void	sort_while_shifting_down(t_stack *a, t_stack *b, int section_len);
int		find_mid_greater_than_first(t_stack *a, int first_mid);
bool	top_is_first_section(t_stack *a, int first_mid);
int		count_nums_greater_than_first(t_stack *a, int mid, int first_mid);
bool	not_only_first_section(t_stack *a, int first_mid);

void	slot_to_first_section(t_stack *a, t_stack *b,
			int first_mid, int mid, int *pushed);
void	sort_two(t_stack *a, t_stack *b);
void	init_sorting_functions(t_sorter_ptr sorting[6]);
void	remove_sorted_a(t_sections *sections);
int		find_num_to_add(t_stack *stack, int midpoint);
void	push_first_section(t_stacks *stacks, int to_push, int mid);
void	check_first_half(t_stacks *stacks, t_sections *sections, int *first_mid);
bool	has_remaining(t_stack *a, int first_mid);
void	clear_remaining(t_stacks *stacks,
			t_sections *sections, int first_midpoint);
int		last_node_id(t_stack *stack);
bool	not_dividable_further(t_section *unsorted_a, t_section *first_half);

#endif