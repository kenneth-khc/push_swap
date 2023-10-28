/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 18:59:04 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

# define UP 'U'
# define DOWN 'D'
# define NUM_OF_INSTRUCTIONS 11

typedef struct s_stack				t_stack;
typedef struct s_node				t_node;
typedef struct s_section			t_section;
typedef struct s_section_list		t_section_list;

struct s_stack
{
	t_node	*top;
};
struct s_node
{
	int		data;
	int		simplified;
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

// Arguments
int		*parse_arguments(int argc, char **argv, int *size);
int		*store_one_arg(char **argv, int *size);
int		*store_args(char **argv, int *size);
void	validate_integers(int *list_of_integers, char **argv);
void	init_stacks(t_stack *stack_a, t_stack *stack_b,
			int *list_of_integers, int size);
void	check_for_duplicates(int *array, int size);
void	simplify_stack(int *array, t_stack *stack_a);


// Operations
void	sa(t_stack *stack_a, t_stack *stack_b);
void	sb(t_stack *stack_a, t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, t_stack *stack_b);
void	rb(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, t_stack *stack_b);
void	rrb(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Stack quicksort
void	quicksort(t_stack *a, t_stack *b, int size);
void	sort_three(t_stack *stack_a, t_stack *stack_b);
bool	section_is_sorted(t_node *begin_node, int size);
void	sort_a(t_stack *a, t_stack *b, int num_of_elements, t_section_list *list);
int		stack_len(t_stack *a);
int		find_nums_to_push(int mid, t_stack *stack_a);
void	push_to_b(int to_push, int mid, t_stack *stack_a, t_stack *stack_b);
void	sort_b(t_stack *stack_a, t_stack *stack_b, t_section_list *list);
void	sort_section_b(t_stack *stack_a, t_stack *stack_b, int section_len);
void	push_to_a(int to_push, int mid, t_stack *stack_a, t_stack *stack_b);
int		find_nums_to_push_b(int mid, t_stack *stack, int section_len);
void	push_further_to_b(int to_push, int mid, t_stack *stack_a, t_stack *stack_b);
void	reverse_sort_three_elements(t_stack *stack_a, t_stack *stack_b);
void	reverse_sort_three(t_stack *stack_a, t_stack *stack_b);
int		find_mid_in_section(t_stack *stack, int section_len);


// Real quicksort
void	quick_sort(int *array, int size);
void	quick_sort_recurse(int *array, int start_index, int end_index);
int		partition(int *array, int start_index, int end_index);
void	swap(int *x, int *y);

// Utils
void	push(t_stack *stack, int data);
void	error(void);
int		number_of_strings(char **strings);
bool	elements_are_ascending(t_stack *stack);
bool	elements_are_descending(t_stack *stack);
bool	section_is_ascending(t_stack *stack, int len);
bool	stacks_are_sorted(t_stack *stack_a, t_stack *stack_b);
bool	stacks_are_not_sorted(t_stack *stack_a, t_stack *stack_b);
int		find_midpoint(t_stack *stack);
void	find_min_max(t_stack *stack, int *min, int *max);
void	find_section_min_max(t_stack *stack, int len, int *min, int *max);

// Sections list
void	add_section(int to_sort, t_section_list *list, char stack);

//Testing
void	peek_entire_stack(t_stack stack_a, t_stack stack_b);
void	peek_section_list(t_section_list sections);
void	fill_stack_b_for_test(t_stack *stack_b);
void	execute_instructions_for_test(t_stack *a, t_stack *b);

// organize later
void	sort_current_section(t_stack *stack_a, t_stack *stack_b, t_section *section);
void	remove_section(t_section_list *sections);
void	sort_section_a(t_stack *stack_a, t_stack *stack_b, int section_len);
void	sort_two_a(t_stack *stack_a, t_stack *stack_b);
void    divide_section(t_stack *stack_a, t_stack *stack_b, t_section_list *sections);
int    divide_section_b(t_stack *stack_a, t_stack *stack_b,
t_section *section);
int	divide_section_a(t_stack *stack_a, t_stack *stack_b,
t_section *section);
void	divide_a_until_sorted(t_stack *stack_a, t_stack *stack_b,
t_section_list *sections, t_section *latest_a);
int	push_half_to_b(t_stack *stack_a, t_stack *stack_b,
			t_section_list *sections);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
char	decide_direction_a(t_stack *stack, int mid);

int		find_min(t_stack *stack_a);
void	free_stack(t_stack *stack);
bool	section_is_descending(t_stack *stack, int len);
bool	top_is_ascending(t_stack *stack);
bool	top_is_descending(t_stack *stack);
bool	optimize_swap(t_stack *a, t_stack *b);


#endif