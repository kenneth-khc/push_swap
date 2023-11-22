/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_swaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:00:32 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 19:00:41 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimized_swap(char stack, t_stack *a, t_stack *b)
{
	if (a_top_out_of_place(a) && b_top_out_of_place(b))
		ss(a, b);
	else
	{
		if (stack == 'A')
			sa(a);
		else if (stack == 'B')
			sb(b);
	}
}

bool	b_top_out_of_place(t_stack *s)
{
	return (s->top && s->top->next && s->top->id + 1 == s->top->next->id);
}

bool	a_top_out_of_place(t_stack *s)
{
	return (s->top && s->top->next && s->top->id - 1 == s->top->next->id);
}

bool	top_is_descending(t_stack *s)
{
	return (s->top && s->top->next && s->top->id > s->top->next->id);
}
