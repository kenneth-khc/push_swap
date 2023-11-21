/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:05:15 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/21 17:17:35 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
