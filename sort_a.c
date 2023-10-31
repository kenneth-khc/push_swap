/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 21:14:12 by kecheong         ###   ########.fr       */
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

int	find_nums_to_push(int mid, t_stack *a)
{
	int		to_push;
	t_node	*current;

	to_push = 0;
	current = a->top;
	while (current)
	{
		if (current->id <= mid)
			to_push++;
		current = current->next;
	}
	return (to_push);
}

void	push_to_b(int to_push, int mid, t_stack *a, t_stack *b)
{
	char	direction;
	bool	checked;

	checked = false;
	while (to_push)
	{
		if (!checked)
			direction = decide_direction_a(a, mid, &checked);
		if (a->top->id <= mid)
		{
			pb(a, b);
			to_push--;
			checked = false;
		}
		else
			shift_stack(a, b, direction, 'A');
	}
}
