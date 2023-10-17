/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:38:14 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/10 17:03:44 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_number_to_push(int mid, t_stack *stack_a)
{
	int		to_push;
	t_node	*current;

	to_push = 0;
	current = stack_a->top;
	while (current)
	{
		if (current->simplified <= mid)
			to_push++;
		current = current->next;
	}
	return (to_push);
}

void	push_to_b(int to_push, int mid, t_stack *stack_a, t_stack *stack_b)
{
	while (to_push)
	{
		if (stack_a->top->simplified <= mid)
		{
			pb(stack_a, stack_b);
			to_push--;
		}
		else
			ra(stack_a, stack_b);
	}
}