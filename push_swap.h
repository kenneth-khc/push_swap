/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/13 01:55:12 by kecheong         ###   ########.fr       */
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
typedef struct s_instruction		t_instruction;
typedef void						(*t_function_pointer)();
// (t_stack *a, t_stack *b);
typedef struct s_instruction_table	t_instruction_table;

struct s_stack
{
	t_node	*top;
};

struct s_node
{
	int		data;
	t_node	*next;
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

void	init_stacks(int *list_of_integers, int size, t_stack *a, t_stack *b);
int		*parse_arguments(int argc, char **argv, int *size);
int		*store_one_arg(char **argv, int *size);
int		*store_args(char **argv, int *size);
void	sorting(t_stack *stack_a, t_stack *stack_b, int size);
int		find_min(t_stack *stack_a);

// Operations
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
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
void	check_for_duplicates(int *list_of_integers, int size);
int		number_of_strings(char **strings);
bool	stack_is_sorted(t_stack *stack);
bool	stack_has_elements(t_stack *stack);
void	free_and_move_list(t_instruction **node);

//Checker
void	read_and_exec_instructions(t_instruction *list_of_instructions,
			t_stack *a, t_stack *b);
void	init_instruction_table(t_instruction_table(*instruction_table)[]);
void	validate_instruction(char *instruction,
			t_instruction_table (*instruction_table)[]);
void	execute_instructions(t_instruction *list_of_instructions,
			t_instruction_table (*instruction_table)[], t_stack *a, t_stack *b);

//Testing
void	peek_entire_stack(t_stack stack_a, t_stack stack_b);
void	fill_stack_b_for_test(t_stack *stack_b);
void	execute_instructions_for_test(t_stack *a, t_stack *b);

#endif