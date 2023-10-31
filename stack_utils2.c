/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:44:47 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 21:05:10 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds the min and max within a stack and assigns it to
 * two integers passed in by reference.
 */
void	find_min_max(t_stack *stack, int *min, int *max)
{
	t_node	*current;

	current = stack->top;
	*min = current->id;
	*max = current->id;
	while (current)
	{
		if (current->id <= *min)
			*min = current->id;
		if (current->id >= *max)
			*max = current->id;
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

void	assign_three_nodes(t_stack *a,
		t_node **first, t_node **second, t_node **third)
{
	*first = a->top;
	if (*first)
	{
		*second = (*first)->next;
		if (*second)
			*third = (*second)->next;
		else
			*third = NULL;
	}
}

void	push_sorted_section(t_stack *a, t_stack *b, int section_len)
{
	while (section_len--)
		pa(a, b);
}

void	push_to_opposite_stack(t_stack *a, t_stack *b, char current_stack)
{
	if (current_stack == 'A')
	{
		if (a->top->next && a->top->id < a->top->next->id)
			optimized_swap('A', a, b);
		pb(a, b);
	}
	else if (current_stack == 'B')
	{
		if (b->top->next && b->top->id < b->top->next->id)
			optimized_swap('B', a, b);
		pa(a, b);
	}
}
