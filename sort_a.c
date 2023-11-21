/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/21 13:51:20 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** 
 * Divides stack A in half by pushing half of its elements to stack B.
 * A section is added for each group of numbers pushed.
 * The number of elements pushed is returned for further recursive calls.
*/
int	push_half_to_b(t_stack *a, t_stack *b, t_sections *sections, int first_mid)
{
	int	midpoint;
	int	to_push;

	midpoint = find_mid_ignoring_first(a, first_mid);
	to_push = count_nums_to_push_ignore_first(midpoint, first_mid, a);
	add_section(to_push, sections, 'B');
	to_push += push_to_b(to_push, midpoint, a, b, first_mid);
	sections->head->len -= to_push;
	return (to_push);
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
	t_node	*current;

	// find_min_max(stack, &min, &max);
	current = stack->top;
	min = current->id;
	max = current->id;
	while (current)
	{
		if (current->id <= min)
			min = current->id;
		if (current->id >= max)
			max = current->id;
		current = current->next;
	}
	mid = min + ((max - min) / 2);
	return (mid);
}

/**
 * Count the number of elements lower than the midpoint in stack A
 * and return that as the amount of numbers to push.
 */
int	count_nums_to_push(t_stack *a, int mid)
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


/**
 * Push numbers lower than the midpoint to stack B.
 * If the top number is not lower than the midpoint,
 * shift stack A either up or down until you get to the next target.
 */
int	push_to_b(int to_push, int mid, t_stack *a, t_stack *b, int first_mid)
{
	int	pushed;

	pushed = 0;
	while (to_push)
	{
		if (top_is_first_section(a, first_mid))
		{
			slot_to_first_section(a, b, first_mid, mid, &pushed);
		}
		else if (a->top->id <= mid && a->top->id > first_mid)
		{
			pb(a, b);
			to_push--;
		}
		else
		{
			ra(a);
		}
	}
	return (pushed);
}

bool	not_only_first_section(t_stack *a, int first_mid)
{
	t_node	*current;

	current = a->top;
	while (current->next)
	{
		current = current->next;
		if (current->id > first_mid)
			return (true);
	}
	return (false);
}
