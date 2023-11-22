/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:21:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 18:31:55 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stack(char current_stack, char direction, t_stack *a, t_stack *b)
{
	if (current_stack == 'A')
	{
		if (direction == UP)
		{
			if (rr_optimizable(b))
				rr(a, b);
			else
				ra(a);
		}
		else if (direction == DOWN)
		{
			if (rrr_optimizable(b))
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

bool	rr_optimizable(t_stack *b)
{
	return (b->top->id < last_node_id(b));
}

bool	rrr_optimizable(t_stack *b)
{
	return (b->top->id > last_node_id(b));
}
