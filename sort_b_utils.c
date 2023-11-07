/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:23:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/07 12:49:32 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	section_is_descending(t_stack *stack, int len)
{
	t_node	*current;
	int		prev;

	current = stack->top;
	prev = current->id;
	while (--len)
	{
		current = current->next;
		if (prev < current->id)
			return (false);
		prev = current->id;
	}
	return (true);
}

char	decide_direction_b(t_stack *stack, int midpoint, bool *checked)
{
	t_node	*current;
	int		steps_to_target;

	current = stack->top;
	steps_to_target = 0;
	while (current->id < midpoint)
	{
		current = current->next;
		steps_to_target++;
	}
	*checked = true;
	if (steps_to_target <= midpoint)
		return (UP);
	else
		return (DOWN);
}

int	push_section_to_a(int to_push, int mid, t_stack *a, t_stack *b)
{
	char	direction;
	int		shifted_up;
	bool	checked;

	shifted_up = 0;
	checked = false;
	bool	sorting;
	if (to_push <= 3)
		sorting = true;
	else
		sorting = false;
	while (to_push)
	{
		if (b->top->id > mid)
		{
			pa(a, b);
			to_push--;
			if (sorting && a->top->id > a->top->next->id)
				optimized_swap('A', a, b);
			checked = false;
		}
		else
		{
			if (!checked)
				direction = decide_direction_b(b, mid, &checked);
			shift_stack('B', a, b, direction);
			shifted_up++;
		}
	}
	// while (shifted_up--)
	// 	rrb(b);
	return (shifted_up);
}

void	push_last_section(int to_push, int mid, t_stack *a, t_stack *b)
{
	char	direction;
	bool	checked;

	checked = false;
	while (to_push)
	{
		if (b->top->id > mid)
		{
			pa(a, b);
			if (--to_push == 0)
				break ;
			checked = false;
		}
		else
		{
			if (!checked)
				direction = decide_direction_b(b, mid, &checked);
			shift_stack('B', a, b, direction);
		}
	}
}

int	pushback_to_b(int to_push, int mid, t_stack *a, t_stack *b)
{
	int		shifted_up;

	shifted_up = 0;
	while (to_push)
	{
		if (a->top->id <= mid)
		{
			pb(a, b);
			to_push--;
		}
		else
		{
			ra(a);
			shifted_up++;
		}
	}
	// while (shifted_up--)
	// {
	// 	rra(a);
	// }
	return (shifted_up);
}
