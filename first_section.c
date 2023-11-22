/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:40:15 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:09:00 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_first_half(t_stacks *stacks, t_sections *sections, int *first_mid)
{
	t_stack		*a;
	t_stack		*b;
	int			to_push;
	t_section	*unsorted_a;
	t_section	*first_half;

	a = stacks->a;
	b = stacks->b;
	unsorted_a = sections->head;
	*first_mid = find_section_midpoint(a, unsorted_a->len);
	to_push = count_nums_to_push(a, *first_mid);
	add_unsorted_section('B', to_push, sections);
	first_half = unsorted_a->next;
	if (not_dividable_further(unsorted_a, first_half))
	{
		push_first_section(stacks, first_half->len, *first_mid);
		unsorted_a->len -= first_half->len;
	}
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

void	slot_into_first(t_stacks *stacks, int first_mid, int mid, int *pushed)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	pb(a, b);
	*pushed += 1;
	if (top_is_first_section(a, first_mid) && a->top->id > b->top->id)
		slot_into_first(stacks, first_mid, mid, pushed);
	if (has_two_elements(b) && not_only_first_section(b, first_mid))
	{
		if (a->top->id > mid)
			rr(a, b);
		else
			rb(b);
	}
}

void	clear_remaining(t_stacks *stacks, t_sections *sections, int first_mid)
{
	t_stack	*a;
	t_stack	*b;
	int		pushed;
	int		remaining;

	a = stacks->a;
	b = stacks->b;
	remaining = count_nums_to_push(a, first_mid);
	pushed = remaining;
	while (remaining > 0)
	{
		if (a->top->id <= first_mid)
		{
			pb(a, b);
			remaining--;
			if (not_only_first_section(b, first_mid))
				shift_stack('B', UP, a, b);
		}
		else
			shift_stack('A', UP, a, b);
	}
	sections->head->len -= pushed;
}
