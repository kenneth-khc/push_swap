/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/16 18:57:09 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pingpong(t_stack *a, t_stack *b, int size)
{
	int				temp;
	int				sections;
	t_section_list	list;

	temp = size;
	sections = 0;
	while (temp > 3)
	{
		temp /= 2;
		sections++;
	}
	printf("sections:%d\n", sections);
	printf("SIZE: %d\n", size);
	init_list_of_sections(&list);
	sort_a(a, b, size, &list);
	// peek_entire_stack(*a, *b);
	t_section *current;
	current = list.head;
	while (current)
	{
		printf("TO SORT: %d\n", current->len);
		current = current->next;
	}
	sort_b(a, b, &list);
	peek_entire_stack(*a, *b);
}

void	sort_a(t_stack *a, t_stack *b, int num_of_elements,
		t_section_list *list)
{
	int		mid;
	int		to_push;
	int		*temp_array;

	if (stack_len(a) <= 3)
	{
		sort_three_elements(a);
		return ;
	}
	temp_array = init_temp_array(a);
	mid = find_mid(temp_array, num_of_elements);
	free(temp_array);
	to_push = find_number_to_push(mid, a);
	add_section(to_push, list);
	printf("LIST HEAD TO PUSH: %d %d\n", list->head->len, list->tail->len);
	printf("mid: %d\n", mid);
	printf("to push: %d\n", to_push);
	push_to_b(to_push, mid, a, b);
	sort_a(a, b, num_of_elements / 2, list);
}

/**
 * Sorting 3 elements is simple. 
 * There are only 3! possible permutations.
 * It only takes at most 2 instructions, so abuse this when possible.
 */

void	sort_three_elements(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack->top || !stack->top->next || !stack->top->next->next
		|| section_is_sorted(stack->top, 3))
		return ;
	if (stack->top->simplified > stack->top->next->simplified
		&& !stack->top->next->next)
	{
		sa(stack);
		return ;
	}
	first = stack->top;
	second = first->next;
	third = second->next;
	if (first->data > second->data && first->data > third->data)
	{
		ra(stack);
		if (second->data > third->data)
			sa(stack);
	}
	else if (first->data > second->data)
		sa(stack);
	else if (first->data < second->data)
	{
		rra(stack);
		if (third->data > first->data)
			sa(stack);
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