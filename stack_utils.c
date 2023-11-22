/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:07:45 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/23 00:00:50 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Push an element into the stack.
 * It is now the top element of the stack and points towards the
 * previous top element.
*/
void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (NULL == new_node)
		error();
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
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

void	free_stacks(t_stacks *stacks)
{
	t_node	*current;
	t_node	*prev;

	current = stacks->a->top;
	prev = NULL;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	free(stacks->a);
	current = stacks->b->top;
	prev = NULL;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	free(stacks->b);
}

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

/**
 * Find the midpoint in the section by halving
 * the minimum and maximum index.
 */
int	find_section_midpoint(t_stack *stack, int section_len)
{
	int		min;
	int		max;
	int		mid;
	t_node	*current;

	current = stack->top;
	min = current->id;
	max = current->id;
	while (section_len > 0)
	{
		if (current->id <= min)
			min = current->id;
		if (current->id >= max)
			max = current->id;
		current = current->next;
		section_len--;
	}
	mid = min + ((max - min) / 2);
	return (mid);
}
