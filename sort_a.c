/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 18:01:09 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_half_to_b(t_stack *a, t_stack *b, t_section_list *sections)
{
	int	midpoint;
	int	elements;

	midpoint = find_midpoint(a);
	elements = find_nums_to_push(midpoint, a);
	push_to_b(elements, midpoint, a, b);
	add_section(elements, sections, 'B');
	return (elements);
}

/**
 * Find the midpoint in the stack by halving
 * the minimum and maximum index.
 */
int	find_midpoint(t_stack *stack)
{
	int		min;
	int		max;
	int		mid;

	find_min_max(stack, &min, &max);
	mid = min + ((max - min) / 2);
	return (mid);
}

int	find_nums_to_push(int mid, t_stack *stack_a)
{
	int		to_push;
	t_node	*current;

	to_push = 0;
	current = stack_a->top;
	while (current)
	{
		if (current->simplified <= mid)
			to_push++;
		current = current->next;
	}
	return (to_push);
}

void	push_to_b(int to_push, int mid, t_stack *stack_a, t_stack *stack_b)
{
	char	direction;

	while (to_push)
	{
		if (stack_a->top->simplified <= mid)
		{
			pb(stack_a, stack_b);
			to_push--;
		}
		else
		{
			direction = decide_direction_a(stack_a, mid);
			if (direction == UP)
				ra(stack_a, stack_b);
			else if (direction == DOWN)
				rra(stack_a, stack_b);
		}
	}
}