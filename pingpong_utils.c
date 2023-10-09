/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpong_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:38:14 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/09 21:59:02 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_temp_array(t_stack *a)
{
	t_node	*current;
	int		size;
	int		*array;
	int		i;

	current = a->top;
	size = stack_len(a);
	array = malloc(sizeof(int) * size);
	if (!array)
		error();
	i = 0;
	while (current)
	{
		array[i++] = current->simplified;
		current = current->next;
	}
	return (array);
}

int	stack_len(t_stack *a)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	find_mid(int *array, int size)
{
	int	i;
	int	min;
	int	max;
	int	mid;

	i = 1;
	min = array[0];
	max = array[0];
	while (i < size)
	{
		if (array[i] <= min)
			min = array[i];
		if (array[i] >= max)
			max = array[i];
		i++;
	}
	mid = min + ((max - min) / 2);
	// if (mid == 4)
	// 	mid++;
	return (mid);
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
