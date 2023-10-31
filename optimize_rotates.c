/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:21:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/30 17:33:09 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rr_optimizable(t_stack *a, t_stack *b)
{
	t_node	*last;

	(void)a;
	last = b->top;
	if (last)
	{
		while (last->next)
			last = last->next;
		if (b->top->id < last->id)
			return (true);
		if (b->top->next)
		{
			if (b->top->next->id < last->id)
			{
				optimized_swap('B', a, b);
				return (true);
			}
		}
	}
	return (false);
}

bool	rrr_optimizable(t_stack *a, t_stack *b)
{
	t_node	*last;

	(void)a;
	last = b->top;
	if (last)
	{
		while (last->next)
			last = last->next;
		if (b->top->id > last->id)
			return (true);
		if (b->top->next)
		{
			if (b->top->next->id > last->id)
			{
				optimized_swap('B', a, b);
				return (true);
			}
		}
	}
	return (false);
}
