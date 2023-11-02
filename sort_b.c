/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:50:23 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/02 11:49:24 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_section_a(t_stack *a, t_stack *b, int section_len)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (section_is_ascending(a, section_len))
		return ;
	assign_three_nodes(a, &first, &second, &third);
	if (third && third->id != third->next->id - 1)
	{
		if (first->id == third->next->id - 1)
			optimized_swap('A', a, b);
		ra(a, b);
		optimized_swap('A', a, b);
		rra(a, b);
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
		rb(a, b);
		optimized_swap('B', a, b);
		pa(a, b);
		section_len -= 1;
		rrb(a, b);
	}
	while (section_len--)
		push_to_opposite_stack(a, b, 'B');
}

void	sort_section_a_5(t_stack *a, t_stack *b, int section_len)
{
	int	len;

	len = section_len;
	if (section_is_ascending(a, section_len))
		return ;
	// if (len == 5)
	// 	sort_five(a, b);
	// else if (len == 4)
	// 	sort_four(a, b);
	if (len == 6)
		sort_six2(a, b);
	else if (len == 5)
		sort_five2(a, b);
	else if (len == 4)
		sort_four2(a, b);
	else if (len == 3)
		sort_three2(a, b);
	else if (len == 2)
		if (a->top->id > a->top->next->id)
			optimized_swap('A', a, b);
	return ;
}
