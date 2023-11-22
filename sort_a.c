/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:09:25 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** 
 * Divides stack A in half by pushing half of its elements to stack B.
 * A section is added for each group of numbers pushed.
 * The number of elements pushed is returned for further recursive calls.
*/
void	half_a_to_b(t_stacks *stacks, t_sections *sections, int first_mid)
{
	t_stack	*a;
	int		midpoint;
	int		to_push;
	int		first_section_pushed;

	a = stacks->a;
	midpoint = find_mid_greater_than_first(a, first_mid);
	to_push = count_nums_greater_than_first(a, first_mid, midpoint);
	first_section_pushed = push_to_b(stacks, first_mid, midpoint, to_push);
	add_unsorted_section('B', to_push, sections);
	sections->head->len -= to_push + first_section_pushed;
}

int	find_mid_greater_than_first(t_stack *a, int first_mid)
{
	int		min;
	int		max;
	int		mid;
	t_node	*current;

	current = a->top;
	while (current->id <= first_mid)
		current = current->next;
	min = current->id;
	max = current->id;
	while (current)
	{
		if (current->id > first_mid && current->id <= min)
			min = current->id;
		if (current->id > first_mid && current->id >= max)
			max = current->id;
		current = current->next;
	}
	mid = min + ((max - min) / 2);
	return (mid);
}

int	count_nums_greater_than_first(t_stack *a, int first_mid, int mid)
{
	int		to_push;
	t_node	*current;

	to_push = 0;
	current = a->top;
	while (current)
	{
		if (current->id > first_mid && current->id <= mid)
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
int	push_to_b(t_stacks *stacks, int first_mid, int mid, int to_push)
{
	t_stack	*a;
	t_stack	*b;
	int		first_section_pushed;

	a = stacks->a;
	b = stacks->b;
	first_section_pushed = 0;
	while (to_push > 0)
	{
		if (top_is_first_section(a, first_mid))
			slot_into_first(stacks, first_mid, mid, &first_section_pushed);
		else if (!top_is_first_section(a, first_mid) && a->top->id <= mid)
		{
			pb(a, b);
			to_push--;
		}
		else
			ra(a);
	}
	return (first_section_pushed);
}
