/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:24:22 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:40:08 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Operations to shift the stack downwards. */

#include "push_swap.h"

/* Shift stack A downwards. */
void	rra(t_stack *a)
{
	t_node	*first;
	t_node	*second_last;

	if (NULL == a->top || NULL == a->top->next)
		return ;
	first = a->top;
	second_last = a->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	a->top = second_last->next;
	second_last->next = NULL;
	ft_printf("rra\n");
}

/* Shift stack B downwards. */
void	rrb(t_stack *b)
{
	t_node	*first;
	t_node	*second_last;

	if (NULL == b->top || NULL == b->top->next)
		return ;
	first = b->top;
	second_last = b->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	b->top = second_last->next;
	second_last->next = NULL;
	ft_printf("rrb\n");
}

/* Shift both stack A and stack B downwards. */
void	rrr(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second_last;

	if (NULL == a->top || NULL == a->top->next)
		return ;
	first = a->top;
	second_last = a->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	a->top = second_last->next;
	second_last->next = NULL;
	if (NULL == b->top || NULL == b->top->next)
		return ;
	first = b->top;
	second_last = b->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	b->top = second_last->next;
	second_last->next = NULL;
	ft_printf("rrr\n");
}
