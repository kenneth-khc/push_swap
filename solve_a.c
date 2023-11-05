/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:28:54 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/05 20:06:17 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorting 3 elements is simple. 
 * There are only 3! possible permutations.
 * It only takes at most 2 instructions, so abuse this when possible.
 */
void	sort_three(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (elements_are_ascending(a))
		return ;
	first = a->top;
	second = first->next;
	third = second->next;
	if (first->id > second->id
		&& first->id > third->id)
	{
		ra(a, b);
		if (second->id > third->id)
			optimized_swap('A', a, b);
	}
	else if (first->id > second->id)
		optimized_swap('A', a, b);
	else if (first->id < second->id)
	{
		rra(a, b);
		if (third->id > first->id)
			optimized_swap('A', a, b);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	smallest;

	smallest = find_min(a);
	while (1)
	{
		if (a->top->id == smallest)
		{
			pb(a, b);
			break ;
		}
		//fix this
		ra(a, b);
	}
	sort_three(a, b);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	smallest;
	int	second_smallest;
	int	to_push;

	smallest = find_min(a);
	second_smallest = smallest + 1;
	to_push = 2;
	while (to_push)
	{
		if (a->top->id == smallest
			|| a->top->id == second_smallest)
		{
			pb(a, b);
			to_push--;
			continue ;
		}
		ra(a, b);
	}
	sort_three(a, b);
	if (b->top->id < b->top->next->id)
		optimized_swap('B', a, b);
	pa(a, b);
	pa(a, b);
}
