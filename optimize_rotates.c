/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:21:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/21 17:18:47 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stack(char direction, char current_stack, t_stack *a, t_stack *b)
{
	if (current_stack == 'A')
	{
		if (direction == UP)
		{
			if (rr_optimizable(a, b))
				rr(a, b);
			else
				ra(a);
		}
		else if (direction == DOWN)
		{
			if (rrr_optimizable(a, b))
				rrr(a, b);
			else
				rra(a);
		}
	}
	else if (current_stack == 'B')
	{
		if (direction == UP)
			rb(b);
		else if (direction == DOWN)
			rrb(b);
	}
}

bool	rr_optimizable(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*last;

	(void)a;
	first = b->top;
	last = first;
	if (last)
	{
		while (last && last->next)
			last = last->next;
		if (first->id < last->id)
			return (true);
	}
	return (false);
}

bool	rrr_optimizable(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*last;

	(void)a;
	first = b->top;
	last = first;
	if (last)
	{
		while (last && last->next)
			last = last->next;
		if (first->id > last->id)
			return (true);
	}
	return (false);
}

void	optimized_rotate(t_stacks *stacks, char current_stack)
{
	if (current_stack == 'A')
	{
		(void)stacks;
	}
}
