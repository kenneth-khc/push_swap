/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:24:22 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 22:10:05 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Shift both stack A and stack B downwards. */
void	rrr(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second_last;

	first = a->top;
	second_last = a->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	a->top = second_last->next;
	second_last->next = NULL;
	first = b->top;
	second_last = b->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	b->top = second_last->next;
	second_last->next = NULL;
}
