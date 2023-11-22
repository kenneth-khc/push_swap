/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:38:14 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 23:54:55 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	section_is_ascending(t_stack *stack, int len)
{
	t_node	*current;
	int		prev;

	current = stack->top;
	prev = current->id;
	while (len--)
	{
		current = current->next;
		if (prev > current->id)
			return (false);
		prev = current->id;
	}
	return (true);
}

void	sort_while_shifting_down(t_stack *a, t_stack *b, int shifted_up)
{
	while (shifted_up--)
	{
		rra(a);
		if (a->top->id > a->top->next->id)
			optimized_swap('A', a, b);
	}
}
