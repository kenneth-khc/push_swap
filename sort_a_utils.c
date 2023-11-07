/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:38:14 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/07 13:51:49 by kecheong         ###   ########.fr       */
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

// del later

int	find_steps_to_reverse_target(t_stack *stack, int midpoint)
{
	int		steps;
	t_node	*current;
	t_node	*last;

	steps = 0;
	current = stack->top;
	last = NULL;
	while (current)
	{
		current = current->next;
		steps++;
		if (current && current->id <= midpoint)
		{
			while (current)
				if (has_next_target(&current, &last, midpoint, &steps))
					continue ;
			else
				return (stack_len(stack) - steps);
		}
	}
	return (stack_len(stack) - steps);
}

bool	has_next_target(t_node **current, t_node **last, int mid, int *steps)
{
	int	steps_to_next_target;

	steps_to_next_target = 0;
	*last = *current;
	while (*current)
	{
		*current = (*current)->next;
		if (!*current)
			return (false);
		steps_to_next_target++;
		if ((*current)->id <= mid)
		{
			*last = *current;
			*steps += steps_to_next_target;
			return (true);
		}
	}
	return (false);
}

char	compare_directions(t_stack *stack, int steps_up, int steps_down)
{
	t_node	*target;
	t_node	*mirrored_target;
	int		i;

	target = stack->top;
	i = 0;
	while (i < steps_up)
	{
		target = target->next;
		i++;
	}
	i = 0;
	mirrored_target = stack->top;
	// steps_down = stack_len(stack) - steps_down;
	while (i < steps_down)
	{
		mirrored_target = mirrored_target->next;
		i++;
	}
	if (target->id > mirrored_target->id)
		return (UP);
	else
		return (DOWN);
}
