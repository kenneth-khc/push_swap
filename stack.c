/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:35 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/10 16:41:55 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int *list_of_integers, int size, t_stack *a, t_stack *b)
{
	a->top = NULL;
	b->top = NULL;
	while (--size >= 0)
		push(a, list_of_integers[size]);
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

// void	pop(t_stack *stack)
// {
// 	if (!stack->top)
// 		return ;
// 	stack->top
// }