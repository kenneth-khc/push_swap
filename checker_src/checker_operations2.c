/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:03 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 23:10:22 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Shift stack A upwards. */
void	ra(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*last;

	(void)b;
	if (!a->top || !a->top->next)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	a->top = first->next;
	first->next = NULL;
}

/* Shift stack B upwards. */
void	rb(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*last;

	(void)a;
	if (!b->top || !b->top->next)
		return ;
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	b->top = first->next;
	first->next = NULL;
}

/* Shift both stack A and stack B upwards. */
void	rr(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (!a->top || !a->top->next)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	a->top = first->next;
	first->next = NULL;
	if (!b->top || !b->top->next)
		return ;
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	b->top = first->next;
	first->next = NULL;
}

/* Shift stack A downwards. */
void	rra(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second_last;

	(void)b;
	if (!a->top || !a->top->next)
		return ;
	first = a->top;
	second_last = a->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	a->top = second_last->next;
	second_last->next = NULL;
}

/* Shift stack B downwards. */
void	rrb(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second_last;

	(void)a;
	if (!b->top || !b->top->next)
		return ;
	first = b->top;
	second_last = b->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	b->top = second_last->next;
	second_last->next = NULL;
}
