/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_section.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:28:21 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/07 14:55:47 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_section(t_stack *a, t_stack *b,
t_section_list *sections)
{
	t_section	*current_section;
	int			pushed;

	current_section = sections->tail;
	if (current_section->in == 'B')
	{
		pushed = divide_section_b(a, b, current_section);
		add_section(pushed, sections, 'A');
	}
	else if (current_section->in == 'A')
	{
		// if (section_is_ascending(a, current_section->len))
		// {
		// 	// remove_current_section_a(current_section);
		// 	return ;
		// }
		// else
			divide_a_until_sorted(a, b, sections, current_section);
	}
}

int	divide_section_b(t_stack *a, t_stack *b,
t_section *section)
{
	int	midpoint;
	int	to_push;
	int	shifted_up;
	bool	slot_in;

	midpoint = find_mid_in_section(b, section->len);
	to_push = count_nums_to_push_b(midpoint, b, section->len);
	section->len -= to_push;
	shifted_up = push_section_to_a(to_push, midpoint, a, b);
	slot_in = false;
	if (to_push <= 3)
	{
		sort_section_a(a, b, to_push);
		slot_in = true;
	}
	if (!last_section_in_b(section))
	{
		while (shifted_up--)
		{
			rrb(b);
			if (section->len > 0 && slot_in && b->top->id == a->top->id - 1)
			{
				pa(a, b);
				section->len--;
				to_push++;
			}
		}
	}
	// else
		// push_last_section(to_push, midpoint, a, b);
	return (to_push);
}

int	count_nums_to_push_b(int mid, t_stack *stack, int section_len)
{
	int		to_push;
	t_node	*current;

	to_push = 0;
	current = stack->top;
	while (section_len > 0)
	{
		if (current->id > mid)
			to_push++;
		current = current->next;
		section_len--;
	}
	return (to_push);
}

void	divide_a_until_sorted(t_stack *a, t_stack *b,
t_section_list *sections, t_section *current_section_a)
{
	int			pushed;

	if (current_section_a->len <= 3)
	{
		sort_section_a(a, b, current_section_a->len);
		remove_current_section_a(sections, current_section_a);
		return ;
	}
	else
	{
		pushed = divide_section_a(a, b, current_section_a);
		add_section(pushed, sections, 'B');
		divide_a_until_sorted(a, b, sections, current_section_a);
	}
}

int	divide_section_a(t_stack *a, t_stack *b,
t_section *section)
{
	int	midpoint;
	int	to_push;
	int	shifted_up;

	midpoint = find_mid_in_section(a, section->len);
	to_push = count_nums_to_push(midpoint, a);
	section->len -= to_push;
	shifted_up = pushback_to_b(to_push, midpoint, a, b);
	if (section->len <= 3)
		sort_while_shifting_down(a, b, shifted_up);
	else
	{
		while (shifted_up--)
		{
			rra(a);
		}
	}
	return (to_push);
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
