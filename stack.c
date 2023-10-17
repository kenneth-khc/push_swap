/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/15 05:21:20 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_for_duplicates(int *array, int size);
static void	simplify_stack(int *array, t_stack *stack_a);

/**
 * Initialize stack A with the arguments passed into the program.
 * The first argument should be at the top of the stack.
 * Initialize stack B to be empty.
 * Create a temporary array for processing.
 * We need it to check for duplicates and to simplify our numbers.
*/

void	init_stacks(t_stack *stack_a, t_stack *stack_b,
	int *list_of_integers, int size)
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
		temp[i] = list_of_integers[i];
		i++;
	}
	quick_sort(temp, size);
	check_for_duplicates(temp, size);
	while (--size >= 0)
		push(stack_a, list_of_integers[size]);
	simplify_stack(temp, stack_a);
	free(temp);
}

/**
 * We do not handle duplicate integers.
 * Check the list of integers for duplicates by sorting it.
 * Iterate through the list, if duplicates are present,
 * they will be placed next to each other.
 * Throw error.
*/

static void	check_for_duplicates(int *array, int size)
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

static void	simplify_stack(int *array, t_stack *stack_a)
{
	int		i;
	t_node	*current;

	current = stack_a->top;
	while (current)
	{
		i = 0;
		while (current->data != array[i])
			i++;
		current->simplified = i;
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

