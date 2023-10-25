/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:52 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/25 10:41:27 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * These are the list of operations permitted to sort the integers
 * among 2 stacks.
*/

#include "push_swap.h"

// void	sa(t_stack *stack_a)
// {
// 	t_node	*temp;
// 	t_node	*temp2;

// 	printf("TOP: %d\n", stack_a->top->data);
// 	printf("TOP NEXT: %d\n", stack_a->top->next->data);
// 	temp = stack_a->top;
// 	temp2 = stack_a->top->next->next;
// 	stack_a->top = stack_a->top->next;
// 	stack_a->top->next = temp;
// 	stack_a->top->next->next = temp2;
// }

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	(void)stack_b;
	if (!stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	(void)stack_a;
	if (!stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_first;
	t_node	*b_first;

	if (!stack_b->top)
		return ;
	a_first = stack_a->top;
	b_first = stack_b->top;
	stack_a->top = b_first;
	stack_b->top = b_first->next;
	b_first->next = a_first;
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_first;
	t_node	*b_first;

	if (!stack_a->top)
		return ;
	a_first = stack_a->top;
	b_first = stack_b->top;
	stack_b->top = a_first;
	stack_a->top = a_first->next;
	a_first->next = b_first;
	ft_printf("pb\n");
}