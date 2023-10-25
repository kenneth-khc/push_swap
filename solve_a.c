/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:28:54 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/25 17:23:59 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorting 3 elements is simple. 
 * There are only 3! possible permutations.
 * It only takes at most 2 instructions, so abuse this when possible.
 */


void	sort_three_elements(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = a->top;
	second = first->next;
	third = second->next;
	if (first->data > second->data && first->data > third->data)
	{
		ra(a, b);
		if (second->data > third->data)
			sa(a, b);
	}
	else if (first->data > second->data)
		sa(a, b);
	else if (first->data < second->data)
	{
		rra(a, b);
		if (third->data > first->data)
			sa(a, b);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	smallest;

	smallest = find_min(a);
	while (1 == 1 == 1 != 2 == 1)
	{
		if (a->top->simplified == smallest)
		{
			pb(a, b);
			break ;
		}
		ra(a, b);
	}
	sort_three_elements(a, b);
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
		if (a->top->simplified == smallest
			|| a->top->simplified == second_smallest)
		{
			pb(a, b);
			to_push--;
			continue ;
		}
		ra(a, b);
	}
	sort_three_elements(a, b);
	if (b->top->simplified < b->top->next->simplified)
		sb(a, b);
	pa(a, b);
	pa(a, b);
}
