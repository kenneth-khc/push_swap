/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_section_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:23:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/23 00:22:46 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_section_b(t_stacks *stacks, t_section *section)
{
	t_stack	*a;
	t_stack	*b;
	int		to_push;
	int		midpoint;
	int		shifted_up;

	a = stacks->a;
	b = stacks->b;
	midpoint = find_section_midpoint(b, section->len);
	to_push = count_nums_to_push_b(midpoint, b, section->len);
	section->len -= to_push;
	shifted_up = half_b_to_a(to_push, midpoint, a, b);
	if (to_push <= 3)
		sort_section_a(a, b, to_push);
	if (!last_section_in_b(section))
		to_push += fix_shifted_stack(stacks, section, shifted_up);
	return (to_push);
}

int	count_nums_to_push_b(int mid, t_stack *stack, int section_len)
{
	int		to_push;
	t_node	*current;

	to_push = 0;
	current = stack->top;
	while (section_len > 0)
	{
		if (current->id > mid)
			to_push++;
		current = current->next;
		section_len--;
	}
	return (to_push);
}

int	half_b_to_a(int to_push, int mid, t_stack *a, t_stack *b)
{
	bool	sortable;
	int		shifted_up;

	sortable = false;
	if (to_push <= 3)
		sortable = true;
	shifted_up = 0;
	while (to_push > 0)
	{
		if (b->top->id > mid)
		{
			pa(a, b);
			to_push--;
			if (sortable && top_is_descending(a))
				optimized_swap('A', a, b);
		}
		else
		{
			shift_stack('B', UP, a, b);
			shifted_up++;
		}
	}
	return (shifted_up);
}

int	fix_shifted_stack(t_stacks *stacks, t_section *section, int shifted_up)
{
	t_stack	*a;
	t_stack	*b;
	int		pushed;

	a = stacks->a;
	b = stacks->b;
	pushed = 0;
	while (shifted_up > 0)
	{
		rrb(b);
		shifted_up--;
		if (section->len > 0 && b->top->id == a->top->id - 1)
		{
			pa(a, b);
			section->len--;
			pushed++;
		}
	}
	return (pushed);
}

bool	last_section_in_b(t_section *current)
{
	while (current)
	{
		current = current->prev;
		if (current && current->in == 'B')
			return (false);
	}
	return (true);
}
