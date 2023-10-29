/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:00:32 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/29 18:39:26 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimized_swap(char stack, t_stack *a, t_stack *b)
{
	if (top_is_ascending(a) && top_is_descending(b))
		ss(a, b);
	else
	{
		if (stack == 'A')
			sa(a, b);
		else if (stack == 'B')
			sb(a, b);
	}
}

bool	top_is_ascending(t_stack *stack)
{
	if (stack->top && stack->top->next)
		if (stack->top->simplified - 1 == stack->top->next->simplified)
			return (true);
	return (false);
}

bool	top_is_descending(t_stack *stack)
{
	if (stack->top && stack->top->next)
		if (stack->top->simplified + 1 == stack->top->next->simplified)
			return (true);
	return (false);
}

bool	optimize_swap(t_stack *a, t_stack *b)
{
	if (top_is_ascending(b) && top_is_descending(a))
	{
		ss(a, b);
		return (true);
	}
	return (false);
}
