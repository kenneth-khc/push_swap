/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/25 19:54:38 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>
# define NUM_OF_INSTRUCTIONS 11

typedef struct s_stack				t_stack;
typedef struct s_node				t_node;
typedef struct s_section			t_section;
typedef struct s_section_list		t_section_list;
typedef struct s_instruction		t_instruction;
typedef void						(*t_function_pointer)();
typedef struct s_instruction_table	t_instruction_table;

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

struct s_instruction
{
	char			*instruction;
	t_instruction	*next;
};

struct s_instruction_table
{
	const char			*instruction_name;
	t_function_pointer	instruction;
};

// Arguments
int		*parse_arguments(int argc, char **argv, int *size);
int		*store_one_arg(char **argv, int *size);
int		*store_args(char **argv, int *size);
void	sorting(t_stack *stack_a, t_stack *stack_b, int size);
int		find_min(t_stack *stack_a);

// quicksort
void	quicksort(t_stack *a, t_stack *b, int size);
void	sort_three_elements(t_stack *stack_a, t_stack *stack_b);
bool	section_is_sorted(t_node *begin_node, int size);
void	sort_a(t_stack *a, t_stack *b, int num_of_elements, t_section_list *list);
int		stack_len(t_stack *a);
int		find_nums_to_push(int mid, t_stack *stack_a);
void	push_to_b(int to_push, int mid, t_stack *stack_a, t_stack *stack_b);
void	sort_b(t_stack *stack_a, t_stack *stack_b, t_section_list *list);
void	sort_section(t_stack *stack_a, t_stack *stack_b, int section_len);
void	push_to_a(int to_push, int mid, t_stack *stack_a, t_stack *stack_b);
int		find_number_to_push_b(int mid, t_stack *stack, int section_len);
bool	elements_left_to_push(int mid, t_stack *stack);
void	pushback_to_b(t_stack *stack_a, t_stack *stack_b, t_section_list *list,
		t_section *section);
void	push_further_to_b(int to_push, int mid, t_stack *stack_a, t_stack *stack_b);
void	reverse_sort_three_elements(t_stack *stack_a, t_stack *stack_b);
void	reverse_sort_three(t_stack *stack_a, t_stack *stack_b);
int		find_mid_in_section(t_stack *stack, int section_len);


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

// Quicksort
void	quick_sort(int *array, int size);
void	quick_sort_recurse(int *array, int start_index, int end_index);
int		partition(int *array, int start_index, int end_index);
void	swap(int *x, int *y);

// Utils
void	push(t_stack *stack, int data);
void	error(void);
void	validate_integers(int *list_of_integers, char **argv);
void	init_stacks(t_stack *stack_a, t_stack *stack_b,
			int *list_of_integers, int size);
int		number_of_strings(char **strings);
bool	stack_is_sorted(t_stack *stack);
bool	stack_is_reverse_sorted(t_stack *stack);
bool	stacks_are_sorted(t_stack *stack_a, t_stack *stack_b);
bool	stack_has_elements(t_stack *stack);
void	free_and_move_list(t_instruction **node);
int		find_midpoint(t_stack *stack);
void	find_min_max(t_stack *stack, int *min, int *max);
void	find_section_min_max(t_stack *stack, int len, int *min, int *max);

//List
void	init_list_of_sections(t_section_list *list);
void	add_section(int to_sort, t_section_list *list, char stack);
void	delete_section(t_section_list *list);


// Checker
void	read_and_exec_instructions(t_instruction *list_of_instructions,
			t_stack *a, t_stack *b);
void	init_instruction_table(t_instruction_table(*instruction_table)[]);
void	validate_instruction(char *instruction,
			t_instruction_table (*instruction_table)[]);
void	execute_instructions(t_instruction *list_of_instructions,
			t_instruction_table (*instruction_table)[], t_stack *a, t_stack *b);

//Testing
void	peek_entire_stack(t_stack stack_a, t_stack stack_b);
void	peek_section_list(t_section_list sections);
void	fill_stack_b_for_test(t_stack *stack_b);
void	execute_instructions_for_test(t_stack *a, t_stack *b);


void	sort_current_section(t_stack *stack_a, t_stack *stack_b, t_section *section);
void	update_section_list(t_section_list *sections);
void	sort_three_a(t_stack *stack_a, t_stack *stack_b);
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

#endif