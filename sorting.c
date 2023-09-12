/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:46:43 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/13 01:18:05 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	min;
	(void)size;
	peek_entire_stack(*stack_a, *stack_b);
	// while (!stack_is_sorted(stack_a, stack_b))
	while (!stack_is_sorted(stack_a))
	{
		if (stack_a->top)
		{
			min = find_min(stack_a);
			while (stack_a->top->data != min)
			{
				ra(stack_a);
			}
		}
		pb(stack_a, stack_b);
	}
	while (stack_has_elements(stack_b))
		pa(stack_a, stack_b);
	// peek_entire_stack(*stack_a, *stack_b);
}

int	find_min(t_stack *stack_a)
{
	int		x;
	t_node	*current;

	current = stack_a->top;
	x = current->data;
	while (current)
	{
		if (current->data <= x)
			x = current->data;
		current = current->next;
	}
	return (x);
}

// bool	stack_is_sorted(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*current;
// 	int		prev;

// 	if (stack_a->top)
// 	{
// 		current = stack_a->top;
// 		prev = current->data;
// 		while (current->next)
// 		{
// 			current = current->next;
// 			if (prev > current->data)
// 				return (false);
// 			prev = current->data;
// 		}
// 		if (!stack_b->top)
// 			return (true);
// 		return (false);
// 	}
// 	if (!stack_b_has_elements(stack_b))
// 		return (true);
// 	return (false);
// }

bool	stack_is_sorted(t_stack *stack)
{
	t_node	*current;
	int		prev;

	if (stack->top)
	{
		current = stack->top;
		prev = current->data;
		while (current->next)
		{
			current = current->next;
			if (prev > current->data)
				return (false);
			prev = current->data;
		}
	}
	return (true);
}

bool	stack_has_elements(t_stack *stack)
{
	if (stack->top)
		return (true);
	return (false);
}