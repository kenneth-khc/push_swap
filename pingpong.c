/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/09 21:42:18 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pingpong(t_stack *a, t_stack *b, int size)
{
	t_section_list	sections;

	if (stack_is_sorted(a))
		return ;

	printf("SIZE: %d\n", size);
	sections.head = NULL;
	sections.tail = NULL;


	sort_a(a, b, size, &sections);

	t_section *current;
	current = sections.head;
	while (current)
	{
		printf("SECTION LIST BEFORE SORT B: %d\n", current->len);
		current = current->next;
	}

	sort_b(a, b, &sections);
}

void	sort_a(t_stack *a, t_stack *b, int num_of_elements,
		t_section_list *list)
{
	int		midpoint_a;
	int		num_elements_to_push;

	if (stack_len(a) <= 3)
	{
		sort_three_elements(a, b);
		return ;
	}
	midpoint_a = find_mid_in_stack(a);
	num_elements_to_push = find_number_to_push(midpoint_a, a);
	add_section(num_elements_to_push, list);
	push_to_b(num_elements_to_push, midpoint_a, a, b);
	sort_a(a, b, num_of_elements - num_elements_to_push, list);
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

	if (!a->top || !a->top->next || !a->top->next->next
		|| section_is_sorted(a->top, 3))
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

/**
 * Check to see if a group of elements are sorted.
 */

bool	section_is_sorted(t_node *begin_node, int size)
{
	t_node	*current;
	int		prev;

	if (begin_node)
	{
		current = begin_node;
		prev = current->data;
		while (--size)
		{
			current = current->next;
			if (prev > current->data)
				return (false);
			prev = current->data;
		}
	}
	return (true);
}


void	sort_three(t_stack *stack_a, t_stack *stack_b)
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
}

void	sort_two(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	first = stack_a->top;
	second = first->next;
	if (first->simplified > second->simplified)
		sa(stack_a, stack_b);
}
