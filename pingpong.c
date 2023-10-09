/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/09 10:46:44 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pingpong(t_stack *a, t_stack *b, int size)
{
	t_section_list	list;

	printf("SIZE: %d\n", size);
	init_list_of_sections(&list);
	sort_a(a, b, size, &list);
	// peek_entire_stack(*a, *b);
	t_section *current;
	current = list.head;
	while (current)
	{
		printf("SECTION LIST BEFORE SORT B: %d\n", current->len);
		current = current->next;
	}
	// exit(0);
	sort_b(a, b, &list);
	peek_entire_stack(*a, *b);
}

void	sort_a(t_stack *a, t_stack *b, int num_of_elements,
		t_section_list *list)
{
	int		mid;
	int		to_push;
	static int	call;

	if (stack_len(a) <= 3)
	{
		sort_three_elements(a, b);
		return ;
	}
	printf("SORT_A CALL %d", ++call);
	if (list->tail)
		printf(" SECTION_LEN: %d\n", list->tail->len);
	fflush(stdout);
	mid = find_mid_in_stack(a);
	to_push = find_number_to_push(mid, a);
	add_section(to_push, list);
	printf("\nMidpoint of sort_a call %d: %d\n", call, mid);
	printf("Numbers to push in sort_a call %d: %d\n\n", call, to_push);
	fflush(stdout);
	push_to_b(to_push, mid, a, b);
	peek_entire_stack(*a, *b);
	sort_a(a, b, num_of_elements - to_push, list);
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

void	fix_a(t_stack *stack_a, t_stack *stack_b, t_section_list *list)
{
	if (list->tail->len <= 3)
	{
		printf("FIXING A\n");
		printf("Elements to fix: %d %d %d\n", stack_a->top->simplified,
			stack_a->top->next->simplified,
			stack_a->top->next->next->simplified);
		fflush(stdout);
		if (list->tail->len == 3)
			sort_three(stack_a, stack_b);
		if (list->tail->len == 2)
			sort_two(stack_a, stack_b);
		delete_section(list);
		return ;
	}
	(void)stack_b;
	// sort_a(stack_a, stack_b, list->tail->len, list);
	divide_section_further(stack_a, stack_b, list, list->tail);
	peek_entire_stack(*stack_a, *stack_b);
	fix_a(stack_a, stack_b, list);
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

void	divide_section_further(t_stack *stack_a, t_stack *stack_b, t_section_list *list,
		t_section *section)
{
	int	*temp_array ;
	int	mid;
	int	to_push;
	static int call;

	printf("Call %d of dividing further in A: section len %d\n", ++call, section->len);
	temp_array = init_temp_array(stack_a);
	mid = find_mid(temp_array, section->len);
	free(temp_array);
	to_push = find_number_to_push(mid, stack_a);
	add_section(to_push, list);
	// printf("\nMidpoint of sort_a call %d: %d\n", call, mid);
	// printf("Numbers to push in sort_a call %d: %d\n\n", call, to_push);
	fflush(stdout);
	// push_to_b(to_push, mid, stack_a, stack_b);
	push_further_to_b(to_push, mid, stack_a, stack_b);
	list->tail->len -= to_push;
	add_section(to_push, list);
	printf("Updated tail in CALL %d DIVIDE FURTHER: %d, new section: %d\n", call, list->tail->prev->len, list->tail->len);
}
