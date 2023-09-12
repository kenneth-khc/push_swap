/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/11 17:42:21 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int *list_of_integers, int size, t_stack *a, t_stack *b)
{
	a->top = NULL;
	b->top = NULL;
	check_for_duplicates(list_of_integers, size);
	while (--size >= 0)
		push(a, list_of_integers[size]);
}

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
