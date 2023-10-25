/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:46:43 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/25 16:56:37 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack_a, t_stack *stack_b, int size)
{
	int		min;
	bool	sorted;

	(void)size;
	sorted = false;
	min = 0;
	while (stack_a->top)
	{
		while (stack_a->top->simplified != min)
		{
			rra(stack_a, stack_b);
		}
		pb(stack_a, stack_b);
		min++;
		// sorted = stack_is_sorted(stack_a);
	}
	while (stack_b->top)
		pa(stack_a, stack_b);
	// peek_entire_stack(*stack_a, *stack_b);
}

int	find_min(t_stack *stack_a)
{
	int		x;
	t_node	*current;

	current = stack_a->top;
	x = current->simplified;
	while (current)
	{
		if (current->simplified <= x)
			x = current->simplified;
		current = current->next;
	}
	return (x);
}

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

bool	stack_is_reverse_sorted(t_stack *stack)
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
			if (prev < current->data)
				return (false);
			prev = current->data;
		}
	}
	return (true);
}

bool	stacks_are_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*prev;

	if (stack_b->top)
		return (false);
	if (stack_a->top)
	{
		current = stack_a->top;
		prev = current;
		while (current->next)
		{
			current = current->next;
			if (prev->simplified > current->simplified)
				return (false);
			prev = prev->next;
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