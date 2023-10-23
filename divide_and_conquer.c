/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:28:21 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/23 21:10:37 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_section(t_stack *stack_a, t_stack *stack_b,
t_section_list *sections)
{
	t_section	*current_section;
	int			pushed;

	current_section = sections->tail;
	if (current_section->in == 'B')
	{
		pushed = divide_section_b(stack_a, stack_b, current_section);
		add_section(pushed, sections, 'A');
	}
	else if (current_section->in == 'A')
	{
		pushed = divide_section_a(stack_a, stack_b, current_section);
		add_section(pushed, sections, 'B');
	}
}

int	divide_section_b(t_stack *stack_a, t_stack *stack_b,
t_section *section)
{
	int	midpoint;
	int	to_push;

	midpoint = find_mid_in_section(stack_b, section->len);
	to_push = find_number_to_push_b(midpoint, stack_b, section->len);
	section->len -= to_push;
	push_to_a(to_push, midpoint, stack_a, stack_b);
	return (to_push);
}

int	divide_section_a(t_stack *stack_a, t_stack *stack_b,
t_section *section)
{
	int	midpoint;
	int	to_push;

	midpoint = find_mid_in_section(stack_a, section->len);
	to_push = find_number_to_push(midpoint, stack_a);
	section->len -= to_push;
	push_further_to_b(to_push, midpoint, stack_a, stack_b);
	return (to_push);
}
