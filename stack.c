/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/20 21:33:36 by kecheong         ###   ########.fr       */
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
void	init_stacks(t_stack *stack_a, t_stack *stack_b,
	t_int_array *int_array)
{
	int	*temp;
	int	i;
	int	temp_size;

	stack_a->top = NULL;
	stack_b->top = NULL;
	temp = malloc(sizeof(*temp) * int_array->size);
	temp_size = int_array->size;
	if (!temp)
		error();
	i = 0;
	while (i < temp_size)
	{
		temp[i] = int_array->buf[i];
		i++;
	}
	quick_sort(temp, temp_size);
	check_for_duplicates(temp, temp_size);
	while (--temp_size >= 0)
		push(stack_a, int_array->buf[temp_size]);
	simplify_stack(temp, stack_a);
	free(temp);
	free(int_array->buf);
	free(int_array);
}

/**
 * We do not handle duplicate integers.
 * Check for duplicates by iterating through a sorted list,
 * if duplicates are present, they will be placed next to each other.
 * Throw error.
*/
void	check_for_duplicates(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] == array[i + 1])
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
void	simplify_stack(int *array, t_stack *stack_a)
{
	int		i;
	t_node	*current;

	current = stack_a->top;
	while (current)
	{
		i = 0;
		while (current->data != array[i])
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

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error();
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
}
