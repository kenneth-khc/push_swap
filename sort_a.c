/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/10 22:55:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** 
 * Divides stack A in half by pushing half of its elements to stack B.
 * A section is added for each group of numbers pushed.
 * The number of elements pushed is returned for further recursive calls.
*/
int	push_half_to_b(t_stack *a, t_stack *b, t_section_list *sections, int first_midpoint)
{
	int	midpoint;
	int	to_push;
	t_section	*current_section;

	current_section = sections->tail;
	// midpoint = find_midpoint(a);
	///?midpoint = find_mid_ignoring_first(a, first_midpoint);
	// to_push = count_nums_to_push(midpoint, a);
	to_push = count_nums_to_push_ignore_first
		(current_section->midpoint, first_midpoint, a);
	push_to_b(to_push, midpoint, a, b, first_midpoint);
	add_section(to_push, sections, 'B');
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

	find_min_max(stack, &min, &max);
	mid = min + ((max - min) / 2);
	return (mid);
}

/**
 * Count the number of elements lower than the midpoint in stack A
 * and return that as the amount of numbers to push.
 */
int	count_nums_to_push(int mid, t_stack *a)
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
void	push_to_b(int to_push, int mid, t_stack *a, t_stack *b, int first_mid)
{
	// char	direction;
	// bool	checked;
	bool	flag;

	// checked = false;
	flag = false;
	while (to_push)
	{
		if (flag && b->top && b->top->next && b->top->id < b->top->next->id)
		{
			if (a->top->id > mid)
				rr(a, b);
			else
				rb(b);
			flag = false;
		}
		else if (top_is_first_section(a, first_mid))
		{
			pb(a, b);
			flag = true;
		}
		else if (a->top->id <= mid && flag == false)
		{
			pb(a, b);
			to_push--;
			// checked = false;
		}
		else
		{
			// if (!checked)
				// direction = decide_direction_a(a, mid, &checked);
			// shift_stack('A', a, b, direction);
			ra(a);
		}
	}
}
