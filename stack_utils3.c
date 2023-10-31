/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:05:15 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 21:06:00 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stack(t_stack *a, t_stack *b, char direction, char current_stack)
{
	if (current_stack == 'A')
	{
		if (direction == UP)
		{
			if (rr_optimizable(a, b))
				rr(a, b);
			else
				ra(a, b);
		}
		else if (direction == DOWN)
		{
			if (rrr_optimizable(a, b))
				rrr(a, b);
			else
				if (current_stack == 'A')
					rra(a, b);
		}
	}
	else if (current_stack == 'B')
	{
		if (direction == UP)
			rb(a, b);
		else if (direction == DOWN)
			rrb(a, b);
	}
}
