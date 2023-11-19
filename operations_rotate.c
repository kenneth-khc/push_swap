/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:03 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/19 20:12:48 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift stack A upwards. */
void	ra(t_stack *a)
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
	ft_printf("ra\n");
}

/* Shift stack B upwards. */
void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (!b->top || !b->top->next)
		return ;
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	b->top = first->next;
	first->next = NULL;
	ft_printf("rb\n");
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
	ft_printf("rr\n");
}
