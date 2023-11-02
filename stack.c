/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/02 11:50:28 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initialize stack A with the arguments passed into the program.
 * The first argument should be at the top of the stack.
 * Initialize stack B to be empty.
 * Create a temporary array for processing.
 * We need it to check for duplicates and to simplify our numbers.
*/
void	init_stacks(t_stack *stack_a, t_stack *stack_b,
	int *integers, int size)
{
	int	*temp;
	int	i;

	stack_a->top = NULL;
	stack_b->top = NULL;
	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		error();
	i = 0;
	while (i < size)
	{
		temp[i] = integers[i];
		i++;
	}
	quick_sort(temp, size);
	check_for_duplicates(temp, size);
	while (--size >= 0)
		push(stack_a, integers[size]);
	simplify_stack(temp, stack_a);
	free(temp);
	free(integers);
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
