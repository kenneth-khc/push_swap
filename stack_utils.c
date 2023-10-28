/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:07:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 13:27:49 by kecheong         ###   ########.fr       */
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
int	number_of_strings(char **strings)
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
	*min = current->simplified;
	*max = current->simplified;
	while (len > 0)
	{
		if (current->simplified <= *min)
			*min = current->simplified;
		if (current->simplified >= *max)
			*max = current->simplified;
		current = current->next;
		len--;
	}
}

bool	stacks_are_not_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*prev;

	if (stack_b->top)
		return (true);
	if (stack_a->top)
	{
		current = stack_a->top;
		prev = current;
		while (current->next)
		{
			current = current->next;
			if (prev->simplified > current->simplified)
				return (true);
			prev = prev->next;
		}
	}
	return (false);
}

/**
 * Finds the min and max within a stack and assigns it to
 * two integers passed in by reference.
 */
void	find_min_max(t_stack *stack, int *min, int *max)
{
	t_node	*current;

	current = stack->top;
	*min = current->simplified;
	*max = current->simplified;
	while (current)
	{
		if (current->simplified <= *min)
			*min = current->simplified;
		if (current->simplified >= *max)
			*max = current->simplified;
		current = current->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*prev;

	current = stack->top;
	prev = NULL;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
}
