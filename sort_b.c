/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:50:23 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 18:59:14 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_current_section(t_stack *a, t_stack *b, t_section *section)
{
	if (section->in == 'B')
	{
		sort_section_b(a, b, section->len);
	}
	else if (section->in == 'A')
	{
		// if (section->len == 3)
			sort_section_a(a, b, section->len);
		// else if (section->len == 2)
			// if (a->top->simplified > a->top->next->simplified)
				// sa(a, b);
	}
}

void	sort_section_a(t_stack *a, t_stack *b, int section_len)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (section_is_ascending(a, section_len))
		return ;
	first = a->top;
	second = first->next;
	if (second)
		third = second->next;
	else
		third = NULL;
	if (third && third->simplified != third->next->simplified - 1)
	{
		if (first->simplified == third->next->simplified - 1)
			sa(a, b);
		ra(a, b);
		sa(a, b);
		rra(a, b);
		if (a->top->simplified > a->top->next->simplified)
			sa(a, b);
	}
	else if (first->simplified > second->simplified)
			sa(a, b);
}

void	sort_section_b(t_stack *a, t_stack *b, int section_len)
{
	t_node	*second;
	t_node	*third;

	if (section_is_descending(b, section_len))
	{
		while (section_len--)
			pa(a, b);
		return ;
	}
	second = b->top->next;
	if (second)
		third = second->next;
	if (second && second->simplified == a->top->simplified - 1)
		sb(a, b);
	else if (third && third->simplified == a->top->simplified - 1)
	{
		rb(a, b);
		sb(a, b);
		pa(a, b);
		section_len -= 1;
		rrb(a, b);
	}
	while (section_len--)
	{
		if (b->top->next && b->top->simplified < b->top->next->simplified)
			sb(a, b);
		pa(a, b);
	}
}
