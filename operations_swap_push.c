/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:52 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:39:17 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Operations to push and swap in the stacks. */

#include "push_swap.h"

/* Swap the first two elements of stack A. */
void	sa(t_stack *a)
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
	ft_printf("sa\n");
}

/* Swap the first two elements of stack B. */
void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (NULL == b->top || NULL == b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	ft_printf("sb\n");
}

/* Swap the first two elements of stack A and stack B. */
void	ss(t_stack *a, t_stack *b)
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
	if (NULL == b->top || NULL == b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	ft_printf("ss\n");
}

/* Push the top element from stack B to stack A. */
void	pa(t_stack *a, t_stack *b)
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
	ft_printf("pa\n");
}

/* Push the top element from stack A to stack B. */
void	pb(t_stack *a, t_stack *b)
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
	ft_printf("pb\n");
}
