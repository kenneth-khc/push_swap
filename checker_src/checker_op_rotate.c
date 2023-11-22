/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:52 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 23:46:32 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* List of operations to shift the stack upwards. */

#include "../push_swap.h"

/* Shift stack A upwards. */
void	checker_ra(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*last;

	(void)b;
	if (NULL == a->top || NULL == a->top->next)
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
void	checker_rb(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*last;

	(void)a;
	if (NULL == b->top || NULL == b->top->next)
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
void	checker_rr(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (NULL == a->top || NULL == a->top->next)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	a->top = first->next;
	first->next = NULL;
	if (NULL == b->top || NULL == b->top->next)
		return ;
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	b->top = first->next;
	first->next = NULL;
}
