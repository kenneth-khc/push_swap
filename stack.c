/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/21 15:09:56 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initialize stack A with the arguments passed into the program.
 * The first argument should be at the top of the stack.
 * Initialize stack B to be empty.
 * Create a temporary array for processing.
 * It is used to check for duplicates and to simplify our numbers.
*/
void	init_stacks(t_stacks *stacks, t_int_array *int_array)
{
	t_stack	*a;
	t_stack	*b;
	t_int_array	*sorted;

	sorted = process_numbers(int_array);
	a = malloc(sizeof(*a));
	b = malloc(sizeof(*b));
	if (NULL == a || NULL == b)
		error();
	a->top = NULL;
	b->top = NULL;
	*stacks = (t_stacks){a, b};
	while (--sorted->size >= 0)
		push(a, int_array->buf[sorted->size]);
	simplify_stack(sorted, a);
	free(sorted->buf);
	free(sorted);
	free(int_array->buf);
}

t_int_array	*process_numbers(t_int_array *int_array)
{
	int	i;
	t_int_array	*temp;

	temp = malloc(sizeof(*temp));
	temp->buf = malloc(sizeof(int) * int_array->size);
	temp->size = int_array->size;
	i = 0;
	while (i < temp->size)
	{
		temp->buf[i] = int_array->buf[i];
		i++;
	}
	quick_sort(temp);
	check_for_duplicates(temp);
	return (temp);
}

/**
 * We do not handle duplicate integers.
 * Check for duplicates by iterating through a sorted list,
 * if duplicates are present, they will be placed next to each other.
 * Throw error.
*/
void	check_for_duplicates(t_int_array *array)
{
	int	i;

	i = 0;
	while (i < array->size - 1)
	{
		if (array->buf[i] == array->buf[i + 1])
			error();
		i++;
	}
}

/**
 * Simplify the elements in the stack by assigning the position they should
 * be in in a sorted list.
 * Temporarily sort a copy of the original list, and iterate through the
 * sorted array to find the position the data is in, then assign
 * that number to the node.
 */
void	simplify_stack(t_int_array *array, t_stack *stack_a)
{
	int		i;
	t_node	*current;

	current = stack_a->top;
	while (current)
	{
		i = 0;
		while (current->data != array->buf[i])
			i++;
		current->id = i;
		current = current->next;
	}
}

/**
 * Push an element into the stack.
 * It is now the top element of the stack and point towards the
 * previous top element.
*/
void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (NULL == new_node)
		error();
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
}
