/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:36:58 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/25 19:54:56 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack *a, t_stack *b, int num_of_elements,
		t_section_list *sections)
{
	int	pushed;
	int	len;

	len = stack_len(a);
	if (len > 5)
	{
		pushed = push_half_to_b(a, b, sections);
		sort_a(a, b, num_of_elements - pushed, sections);
	}
	else if (len <= 5)
	{
		if (stack_is_sorted(a))
			return ;
		if (len == 5)
			sort_five(a, b);
		else if (len == 4)
			sort_four(a, b);
		else if (len == 3)
			sort_three_elements(a, b);
		else if (len == 2)
			if (a->top->simplified > a->top->next->simplified)
				sa(a, b);
		return ;
	}
}

int	push_half_to_b(t_stack *a, t_stack *b, t_section_list *sections)
{
	int	midpoint;
	int	elements;

	midpoint = find_midpoint(a);
	elements = find_nums_to_push(midpoint, a);
	push_to_b(elements, midpoint, a, b);
	add_section(elements, sections, 'B');
	return (elements);
}
