/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:50:23 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/05 23:09:31 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_section_a(t_stack *a, t_stack *b, int section_len)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	int		target;

	if (section_is_ascending(a, section_len))
		return ;
	assign_three_nodes(a, &first, &second, &third);
	if (third)
		target = third->next->id - 1;
	if (third && third->id != target)
	{
		if (first->id == target)
			optimized_swap('A', a, b);
		ra(a);
		optimized_swap('A', a, b);
		rra(a);
		if (a->top->id > a->top->next->id)
			optimized_swap('A', a, b);
	}
	else if (first->id > second->id)
		optimized_swap('A', a, b);
}

void	sort_section_b(t_stack *a, t_stack *b, int section_len)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (section_is_descending(b, section_len))
	{
		push_sorted_section(a, b, section_len);
		return ;
	}
	assign_three_nodes(b, &first, &second, &third);
	if (second && second->id == a->top->id - 1)
		optimized_swap('B', a, b);
	else if (third && third->id == a->top->id - 1)
	{
		rb(b);
		optimized_swap('B', a, b);
		pa(a, b);
		section_len -= 1;
		rrb(b);
	}
	while (section_len--)
		push_to_opposite_stack(a, b, 'B');
}
