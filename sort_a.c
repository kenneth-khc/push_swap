/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/23 20:25:48 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack *stack_a, t_stack *stack_b, int num_of_elements,
		t_section_list *sections)
{
	int		midpoint_a;
	int		num_elements_to_push;

	if (stack_len(stack_a) <= 3)
	{
		sort_three_elements(stack_a, stack_b);
		return ;
	}
	midpoint_a = find_midpoint(stack_a);
	num_elements_to_push = find_number_to_push(midpoint_a, stack_a);
	add_section(num_elements_to_push, sections, 'B');
	push_to_b(num_elements_to_push, midpoint_a, stack_a, stack_b);
	sort_a(stack_a, stack_b, num_of_elements - num_elements_to_push, sections);
}

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

	// if (!a->top || !a->top->next || !a->top->next->next
	// 	|| stack_is_sorted(a))
	// 	return ;
	if (stack_is_sorted(a))
		return ;
	if (a->top->simplified > a->top->next->simplified
		&& !a->top->next->next)
	{
		sa(a, b);
		return ;
	}
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

void	sort_three(t_stack *stack_a, t_stack *stack_b, t_section_list *sections)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack_a->top;
	second = first->next;
	third = second->next;
	if (third->simplified != third->next->simplified - 1)
	{
		if (second->simplified == third->next->simplified - 1)
		{
			ra(stack_a, stack_b);
			sa(stack_a, stack_b);
			rra(stack_a, stack_b);
		}
		else if (first->simplified == third->next->simplified - 1)
		{
			sa(stack_a, stack_b);
			ra(stack_a, stack_b);
			sa(stack_a, stack_b);
			rra(stack_a, stack_b);
		}
		if (stack_a->top->simplified > stack_a->top->next->simplified)
			sa(stack_a, stack_b);
	}
	else if (first->simplified > second->simplified)
		sa(stack_a, stack_b);
	delete_matching_section(sections, 3);
}

void	sort_two(t_stack *stack_a, t_stack *stack_b, t_section_list *sections)
{
	t_node	*first;
	t_node	*second;

	first = stack_a->top;
	second = first->next;
	if (first->simplified > second->simplified)
		sa(stack_a, stack_b);
	// (void)stack_b;
	delete_matching_section(sections, 2);
}

void	delete_matching_section(t_section_list *sections, int num_to_delete)
{
	t_section	*current;
	t_section	*new_next;
	t_section	*prev;

	current = sections->tail;
	if (current->len == num_to_delete)
		delete_section(sections);
	else
	{
		while (current->len != num_to_delete)
			current = current->prev;
		new_next = current->next;
		prev = current->prev;
		prev->next = new_next;
		free(current);
	}
}
