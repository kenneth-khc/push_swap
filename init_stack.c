/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 21:58:40 by kecheong         ###   ########.fr       */
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

void	init_stacks(t_stacks *stacks, t_arr *int_array)
{
	t_stack	*a;
	t_stack	*b;
	t_arr	*sorted;

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

t_arr	*process_numbers(t_arr *int_array)
{
	int		i;
	t_arr	*sorted;

	sorted = malloc(sizeof(*sorted));
	sorted->buf = malloc(sizeof(int) * int_array->size);
	sorted->size = int_array->size;
	i = 0;
	while (i < sorted->size)
	{
		sorted->buf[i] = int_array->buf[i];
		i++;
	}
	quick_sort(sorted);
	check_for_duplicates(sorted);
	return (sorted);
}

/**
 * Check for duplicates by iterating through a sorted list,
 * if duplicates are present, they will be placed next to each other.
 * Throw error.
*/
void	check_for_duplicates(t_arr *array)
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
 * Iterates through a sorted array to find the position the data is in,
 * then assign that number to the node.
 */
void	simplify_stack(t_arr *array, t_stack *stack_a)
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
