/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:38:14 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/21 22:36:30 by kecheong         ###   ########.fr       */
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
	int		steps;
	char	direction;

	current = stack->top;
	steps = 0;
	while (current->id > midpoint)
	{
		current = current->next;
		steps++;
	}
	if (steps <= midpoint)
		direction = UP;
	else
		direction = DOWN;
	*checked = true;
	return (direction);
}

void	init_sorting_functions(t_sorter_ptr sorting[6])
{
	sorting[0] = NULL;
	sorting[1] = NULL;
	sorting[2] = sort_two;
	sorting[3] = sort_three;
	sorting[4] = sort_four;
	sorting[5] = sort_five;
}
