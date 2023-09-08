/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/08 23:40:28 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*list_of_integers;
	int		size;
	t_stack	a;
	t_stack	b;

	list_of_integers = NULL;
	size = 0;
	list_of_integers = parse_arguments(argc, ++argv, &size);
	initialize_stack(list_of_integers, size, &a, &b);
}

void	initialize_stack(int *list_of_integers,
		int size, t_stack *a, t_stack *b)
{
	int	i;

	i = size;
	while (i > 0)
	{
		i--;
		push(a, list_of_integers[i]);
	}
	b->top = NULL;
	
}

void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
}
