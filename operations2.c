/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:03 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/08 20:45:15 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	(void)stack_b;
	if (!stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	stack_a->top = first->next;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	(void)stack_a;
	if (!stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	stack_b->top = first->next;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, stack_b);
	rb(stack_a, stack_b);
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second_last;

	(void)stack_b;
	if (!stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second_last = stack_a->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	stack_a->top = second_last->next;
	second_last->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second_last;

	(void)stack_a;
	if (!stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second_last = stack_b->top;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->next = first;
	stack_b->top = second_last->next;
	second_last->next = NULL;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, stack_b);
	rrb(stack_a, stack_b);
}
