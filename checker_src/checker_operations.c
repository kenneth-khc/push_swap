/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:52 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 23:04:47 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * These are the list of operations permitted to sort the integers
 * among 2 stacks.
*/

#include "../push_swap.h"

/* Swap the first two elements of stack A. */
void	sa(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	(void)b;
	if (!a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
}

/* Swap the first two elements of stack B. */
void	sb(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	(void)a;
	if (!b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

/* Swap the first two elements of stack A and stack B. */
void	ss(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	if (!b->top || !a->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

/* Push the top element from stack B to stack A. */
void	pa(t_stack *a, t_stack *b)
{
	t_node	*a_first;
	t_node	*b_first;

	if (!b->top)
		return ;
	a_first = a->top;
	b_first = b->top;
	a->top = b_first;
	b->top = b_first->next;
	b_first->next = a_first;
}

/* Push the top element from stack A to stack B. */
void	pb(t_stack *a, t_stack *b)
{
	t_node	*a_first;
	t_node	*b_first;

	if (!a->top)
		return ;
	a_first = a->top;
	b_first = b->top;
	b->top = a_first;
	a->top = a_first->next;
	a_first->next = b_first;
}