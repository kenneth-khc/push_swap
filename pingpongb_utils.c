/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpongb_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:23:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/08 20:44:47 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_sort_three_elements(t_stack *stack_a, t_stack *stack_b)
{
	int	remaining_elements;

	remaining_elements = stack_len(stack_b);
	if (remaining_elements == 1)
		pa(stack_a, stack_b);
	else if (remaining_elements == 2)
	{
		if (stack_b->top->simplified < stack_b->top->next->simplified)
			sb(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
		reverse_sort_three(stack_a, stack_b);
}

void	reverse_sort_three(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack_b->top;
	second = first->next;
	third = second->next;
	if (first->simplified == stack_a->top->simplified - 1)
	{
		pa(stack_a, stack_b);
		if (second->simplified < third->simplified)
			sb(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (second->simplified == stack_a->top->simplified - 1)
	{
		if (first->simplified < third->simplified)
			rrb(stack_a, stack_b);
		else
			sb(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		rrb(stack_a, stack_b);
		pa(stack_a, stack_b);
		if (first->simplified < second->simplified)
			sb(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
