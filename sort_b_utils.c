/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:23:27 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/17 18:57:39 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_sort_three_elements(t_stack *stack_a, t_stack *stack_b)
{
	int	remaining_elements;

	remaining_elements = stack_len(stack_b);
	if (stack_is_reverse_sorted(stack_b))
	{
		while (remaining_elements--)
			pa(stack_a, stack_b);
		return ;
	}
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

void	push_to_a(int to_push, int mid, t_stack *stack_a, t_stack *stack_b)
{
	int	rotated;

	rotated = 0;
	while (to_push)
	{
		if (stack_b->top->simplified > mid)
		{
			pa(stack_a, stack_b);
			// if (stack_a->top->simplified > stack_a->top->next->simplified)
			// 	sa(stack_a, stack_b);
			if (--to_push == 0)
				break ;
		}
		else
		{
			rb(stack_a, stack_b);
			rotated++;
		}
	}
	while (rotated > 0)
	{
		rrb(stack_a, stack_b);
		rotated--;
	}
}

void	fix_a(t_stack *stack_a, t_stack *stack_b, t_section_list *sections)
{
	t_section	*current_section;

	current_section = sections->tail;
	// here v
	if (current_section->len <= 3)
	{
		if (current_section->len == 3)
			sort_three(stack_a, stack_b, sections);
		else if (current_section->len == 2)
			sort_two(stack_a, stack_b, sections);
		// delete_section(sections);
		return ;
	}
	else
	{
		pushback_to_b(stack_a, stack_b, sections, current_section);
		// peek_entire_stack(*stack_a, *stack_b);
		fix_a(stack_a, stack_b, sections);
		// sort_b(stack_a, stack_b, sections);
	}
}

void	pushback_to_b(t_stack *stack_a, t_stack *stack_b, t_section_list *sections,
		t_section *section)
{
	int			midpoint_a;
	int			to_push;
	t_section	*current_section;

	current_section = sections->tail;
	midpoint_a = find_mid_in_section(stack_a, section->len);
	to_push = find_number_to_push(midpoint_a, stack_a);
	// push_to_b(to_push, mid, stack_a, stack_b);
	current_section->len -= to_push;
	add_section(to_push, sections);
	push_further_to_b(to_push, midpoint_a, stack_a, stack_b);
	// push_to_b(to_push, midpoint_a, stack_a, stack_b);
}

void	push_further_to_b(int to_push, int mid, t_stack *stack_a, t_stack *stack_b)
{
	int	shifted_up;

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
			ra(stack_a, stack_b);
			shifted_up++;
		}
	}
	while (shifted_up--)
		rra(stack_a, stack_b);
	// while (shifted_up--)
		// rra(stack_a, stack_b);
}