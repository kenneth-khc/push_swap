/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_swaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:00:32 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/05 21:51:27 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimized_swap(char stack, t_stack *a, t_stack *b)
{
	if (top_is_ascending(a) && top_is_descending(b))
		ss(a, b);
	else
	{
		if (!stack)
			return ;
		else if (stack == 'A')
			sa(a);
		else if (stack == 'B')
			sb(b);
	}
}

bool	top_is_ascending(t_stack *stack)
{
	if (stack->top && stack->top->next)
		if (stack->top->id - 1 == stack->top->next->id)
			return (true);
	return (false);
}

bool	top_is_descending(t_stack *stack)
{
	if (stack->top && stack->top->next)
		if (stack->top->id + 1 == stack->top->next->id)
			return (true);
	return (false);
}
