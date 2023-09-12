/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/13 01:09:36 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initialize stack A with the arguments passed into the program.
 * The first argument should be at the top of the stack.
 * Initialize stack B to be empty.
*/

void	init_stacks(int *list_of_integers, int size, t_stack *a, t_stack *b)
{
	a->top = NULL;
	b->top = NULL;
	check_for_duplicates(list_of_integers, size);
	while (--size >= 0)
		push(a, list_of_integers[size]);
}

/**
 * We do not handle duplicate integers.
 * Check the list of integers for duplicates by sorting it.
 * Iterate through the list, if duplicates are present,
 * they will be placed next to each other.
 * Throw error.
*/

void	check_for_duplicates(int *list_of_integers, int size)
{
	int	*temp;
	int	i;

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
	i = 0;
	while (i < size - 1)
	{
		if (temp[i] == temp[i + 1])
			error();
		i++;
	}
	free(temp);
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

