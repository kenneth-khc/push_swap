/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:24:22 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 23:46:44 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Swap the first two elements of stack A. */
void	checker_sa(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	(void)b;
	if (NULL == a->top || NULL == a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
}

/* Swap the first two elements of stack B. */
void	checker_sb(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	(void)a;
	if (NULL == b->top || NULL == b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

/* Swap the first two elements of stack A and stack B. */
void	checker_ss(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (NULL == a->top || NULL == a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	if (NULL == b->top || NULL == a->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

/* Push the top element from stack B to stack A. */
void	checker_pa(t_stack *a, t_stack *b)
{
	t_node	*a_first;
	t_node	*b_first;

	if (NULL == b->top)
		return ;
	a_first = a->top;
	b_first = b->top;
	a->top = b_first;
	b->top = b_first->next;
	b_first->next = a_first;
}

/* Push the top element from stack A to stack B. */
void	checker_pb(t_stack *a, t_stack *b)
{
	t_node	*a_first;
	t_node	*b_first;

	if (NULL == a->top)
		return ;
	a_first = a->top;
	b_first = b->top;
	b->top = a_first;
	a->top = a_first->next;
	a_first->next = b_first;
}
