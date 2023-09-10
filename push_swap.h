/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:36 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/10 21:11:54 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;

struct s_stack
{
	t_node	*top;
};

struct s_node
{
	int		data;
	t_node	*next;
};

void	init_stacks(int *list_of_integers, int size, t_stack *a, t_stack *b);
int		*parse_arguments(int argc, char **argv, int *size);
int		*store_one_arg(char **argv, int *size);
int		*store_args(char **argv, int *size);

// Instructions
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);


// Utils
void	push(t_stack *stack, int data);
void	error(void);
void	validate_integers(int *list_of_integers, char **argv);
int		number_of_strings(char **strings);

//Testing
void	peek_entire_stack(t_stack stack_a, t_stack stack_b);
void	fill_stack_b_for_test(t_stack *stack_b);
void	execute_instructions_for_test(t_stack *a, t_stack *b);



#endif