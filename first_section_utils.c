/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_section_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:06:08 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:09:31 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	top_is_first_section(t_stack *a, int first_mid)
{
	return (a->top->id <= first_mid);
}

bool	not_dividable_further(t_section *unsorted_a, t_section *first_half)
{
	return (unsorted_a->len - first_half->len <= 5);
}

bool	has_two_elements(t_stack *stack)
{
	return (stack->top && stack->top->next);
}

bool	has_remaining_first(t_stack *a, int first_mid)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->id <= first_mid)
			return (true);
		current = current->next;
	}
	return (false);
}

bool	not_only_first_section(t_stack *a, int first_mid)
{
	t_node	*current;

	current = a->top;
	while (current->next)
	{
		current = current->next;
		if (current->id > first_mid)
			return (true);
	}
	return (false);
}
