/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:46:43 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 15:47:00 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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