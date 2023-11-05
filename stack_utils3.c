/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:05:15 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/05 23:21:00 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stack(char current_stack, t_stack *a, t_stack *b, char direction)
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

int	find_section_minimum(t_stack *stack, int section_len)
{
	int		min;
	t_node	*current;

	current = stack->top;
	min = current->id;
	while (section_len--)
	{
		if (current->id <= min)
			min = current->id;
		current = current->next;
	}
	return (min);
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
