/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:21:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/05 22:20:44 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
