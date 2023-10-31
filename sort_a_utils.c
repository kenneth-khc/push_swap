/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:38:14 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 21:14:08 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	elements_are_ascending(t_stack *stack)
{
	t_node	*current;
	int		prev;

	if (stack->top)
	{
		current = stack->top;
		prev = current->id;
		while (current->next)
		{
			current = current->next;
			if (prev > current->id)
				return (false);
			prev = current->id;
		}
	}
	return (true);
}

bool	section_is_ascending(t_stack *stack, int len)
{
	t_node	*current;
	int		prev;

	current = stack->top;
	prev = current->id;
	while (len--)
	{
		current = current->next;
		if (prev > current->id)
			return (false);
		prev = current->id;
	}
	return (true);
}

char	decide_direction_a(t_stack *stack, int midpoint, bool *checked)
{
	t_node	*current;
	int		steps_to_target;

	current = stack->top;
	steps_to_target = 0;
	while (current->id > midpoint)
	{
		current = current->next;
		steps_to_target++;
	}
	*checked = true;
	if (steps_to_target <= midpoint)
		return (UP);
	else
		return (DOWN);
}
