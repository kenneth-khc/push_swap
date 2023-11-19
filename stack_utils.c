/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:07:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/19 21:39:08 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks for the len of a stack by iterating through it.
 */
int	stack_len(t_stack *stack_a)
{
	t_node	*current;
	int		i;

	current = stack_a->top;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

/**
 * Determine the size of the integer array by
 * checking how many arguments there are.
 */
int	count_numbers(char **strings)
{
	int	i;

	i = 0;
	while (*strings++)
		i++;
	return (i);
}

int	find_mid_in_section(t_stack *stack, int section_len)
{
	int		min;
	int		max;
	int		mid;

	find_section_min_max(stack, section_len, &min, &max);
	mid = min + ((max - min) / 2);
	return (mid);
}

void	find_section_min_max(t_stack *stack, int len, int *min, int *max)
{
	t_node	*current;

	current = stack->top;
	*min = current->id;
	*max = current->id;
	while (len > 0)
	{
		if (current->id <= *min)
			*min = current->id;
		if (current->id >= *max)
			*max = current->id;
		current = current->next;
		len--;
	}
}

bool	stacks_are_sorted(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*prev;

	if (b->top)
		return (false);
	if (a->top)
	{
		current = a->top;
		prev = current;
		while (current->next)
		{
			current = current->next;
			if (prev->id > current->id)
				return (false);
			prev = prev->next;
		}
	}
	return (true);
}
