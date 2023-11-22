/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:44:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/23 00:01:13 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_three_nodes(t_stack *stack,
t_node **first, t_node **second, t_node **third)
{
	*first = stack->top;
	if (*first)
	{
		*second = (*first)->next;
		if (*second)
			*third = (*second)->next;
		else
			*third = NULL;
	}
	else
	{
		*second = NULL;
		*third = NULL;
	}
}

void	push_sorted_section(t_stack *a, t_stack *b, int section_len)
{
	while (section_len > 0)
	{
		pa(a, b);
		section_len--;
	}
}

bool	section_is_descending(t_stack *stack, int len)
{
	t_node	*current;
	int		prev;

	current = stack->top;
	if (NULL == current)
		return (true);
	prev = current->id;
	while (--len > 0)
	{
		current = current->next;
		if (prev < current->id)
			return (false);
		prev = current->id;
	}
	return (true);
}

int	last_node_id(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current->next)
		current = current->next;
	return (current->id);
}

int	find_min(t_stack *stack_a)
{
	int		x;
	t_node	*current;

	current = stack_a->top;
	x = current->id;
	while (current)
	{
		if (current->id <= x)
			x = current->id;
		current = current->next;
	}
	return (x);
}
