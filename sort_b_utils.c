/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:23:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 18:57:14 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	reverse_sort_three_elements(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	remaining_elements;

// 	remaining_elements = stack_len(stack_b);
// 	if (elements_are_descending(stack_b))
// 	{
// 		while (remaining_elements--)
// 			pa(stack_a, stack_b);
// 		return ;
// 	}
// 	if (remaining_elements == 1)
// 		pa(stack_a, stack_b);
// 	else if (remaining_elements == 2)
// 	{
// 		if (stack_b->top->simplified < stack_b->top->next->simplified)
// 			sb(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 	}
// 	else
// 		reverse_sort_three(stack_a, stack_b);
// }

// void	reverse_sort_three(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*first;
// 	t_node	*second;
// 	t_node	*third;

// 	first = stack_b->top;
// 	second = first->next;
// 	third = second->next;
// 	if (first->simplified == stack_a->top->simplified - 1)
// 	{
// 		pa(stack_a, stack_b);
// 		if (second->simplified < third->simplified)
// 			sb(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 	}
// 	else if (second->simplified == stack_a->top->simplified - 1)
// 	{
// 		if (first->simplified < third->simplified)
// 			rrb(stack_a, stack_b);
// 		else
// 			sb(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		rrb(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 		if (first->simplified < second->simplified)
// 			sb(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 	}
// }

bool	elements_are_descending(t_stack *stack)
{
	t_node	*current;
	int		prev;

	if (stack->top)
	{
		current = stack->top;
		prev = current->simplified;
		while (current->next)
		{
			current = current->next;
			if (prev < current->simplified)
				return (false);
			prev = current->simplified;
		}
	}
	return (true);
}

bool	section_is_descending(t_stack *stack, int len)
{
	t_node	*current;
	int		prev;

	current = stack->top;
	prev = current->simplified;
	while (--len)
	{
		current = current->next;
		if (prev < current->simplified)
			return (false);
		prev = current->simplified;
	}
	return (true);
}

char	decide_direction_b(t_stack *stack, int midpoint)
{
	t_node	*current;
	int		steps_to_target;

	current = stack->top;
	steps_to_target = 0;
	while (current->simplified < midpoint)
	{
		steps_to_target++;
		current = current->next;
	}
	if (steps_to_target <= midpoint)
		return (UP);
	else
		return (DOWN);
}

void	push_to_a(int to_push, int mid, t_stack *stack_a, t_stack *stack_b)
{
	char	direction;
	int		rotated;

	rotated = 0;
	while (to_push)
	{
		if (stack_b->top->simplified > mid)
		{
			pa(stack_a, stack_b);
			if (--to_push == 0)
				break ;
		}
		else
		{
			direction = decide_direction_b(stack_a, mid);
			if (direction == UP)
				rb(stack_a, stack_b);
			else if (direction == DOWN)
				rrb(stack_a, stack_b);
			rotated++;
		}
	}
	while (rotated > 0)
	{
		rrb(stack_a, stack_b);
		rotated--;
	}
}

void	push_further_to_b(int to_push, int mid, t_stack *stack_a, t_stack *stack_b)
{
	int		shifted_up;
	char	direction;

	shifted_up = 0;
	while (to_push)
	{
		if (stack_a->top->simplified <= mid)
		{
			pb(stack_a, stack_b);
			to_push--;
		}
		else
		{
			direction = decide_direction_a(stack_a, mid);
			if (direction == UP)
				ra(stack_a, stack_b);
			else if (direction == DOWN)
				rra(stack_a, stack_b);
			shifted_up++;
		}
	}//here
	while (shifted_up--)
		rra(stack_a, stack_b);
	// while (shifted_up--)
		// rra(stack_a, stack_b);
}