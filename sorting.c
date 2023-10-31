/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:46:43 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 21:34:56 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack_a)
{
	int		x;
	t_node	*current;

	current = stack_a->top;
	x = current->id;
	while (current)
	{
		if (current->id <= x)
			x = current->id;
		current = current->next;
	}
	return (x);
}
