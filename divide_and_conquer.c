/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:28:21 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 17:50:18 by kecheong         ###   ########.fr       */
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
		divide_a_until_sorted(stack_a, stack_b, sections, current_section);
	}
}

int	divide_section_b(t_stack *stack_a, t_stack *stack_b,
t_section *section)
{
	int	midpoint;
	int	to_push;

	midpoint = find_mid_in_section(stack_b, section->len);
	to_push = find_nums_to_push_b(midpoint, stack_b, section->len);
	section->len -= to_push;
	push_to_a(to_push, midpoint, stack_a, stack_b);
	return (to_push);
}

int	find_nums_to_push_b(int mid, t_stack *stack, int section_len)
{
	int		to_push;
	t_node	*current;

	to_push = 0;
	current = stack->top;
	while (section_len > 0)
	{
		if (current->simplified > mid)
			to_push++;
		current = current->next;
		section_len--;
	}
	// while (i < section_len)
	// {
	// 	if (current->simplified >= mid)
	// 		to_push++;
	// 	current = current->next;
	// 	i++;
	// }
	return (to_push);
}

void	divide_a_until_sorted(t_stack *stack_a, t_stack *stack_b,
t_section_list *sections, t_section *latest_a)
{
	t_section	*current_section;
	int			pushed;

	current_section = sections->tail;
	if (latest_a->len <= 3)
	{
		sort_current_section(stack_a, stack_b, latest_a);
		return ;
	}
	else
	{
		pushed = divide_section_a(stack_a, stack_b, latest_a);
		add_section(pushed, sections, 'B');
		divide_a_until_sorted(stack_a, stack_b, sections, latest_a);
	}
}

int	divide_section_a(t_stack *stack_a, t_stack *stack_b,
t_section *section)
{
	int	midpoint;
	int	to_push;

	midpoint = find_mid_in_section(stack_a, section->len);
	to_push = find_nums_to_push(midpoint, stack_a);
	section->len -= to_push;
	push_further_to_b(to_push, midpoint, stack_a, stack_b);
	return (to_push);
}

