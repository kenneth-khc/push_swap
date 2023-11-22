/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_section_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:28:21 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:21:42 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_section(t_stacks *stacks, t_sections *sections)
{
	t_section	*current_section;
	int			pushed;

	current_section = sections->tail;
	if (current_section->in == 'A')
		div_a_till_sorted(stacks, sections, current_section);
	else if (current_section->in == 'B')
	{
		pushed = divide_section_b(stacks, current_section);
		add_unsorted_section('A', pushed, sections);
	}
}

void	div_a_till_sorted(t_stacks *stacks, t_sections *sections,
t_section *current_section_a)
{
	t_stack	*a;
	t_stack	*b;
	int		pushed;

	a = stacks->a;
	b = stacks->b;
	if (current_section_a->len <= 3)
	{
		sort_section_a(a, b, current_section_a->len);
		remove_current_section_a(sections, current_section_a);
		return ;
	}
	else
	{
		pushed = divide_section_a(a, b, current_section_a);
		add_unsorted_section('B', pushed, sections);
		div_a_till_sorted(stacks, sections, current_section_a);
	}
}

int	divide_section_a(t_stack *a, t_stack *b,
t_section *section)
{
	int	midpoint;
	int	to_push;
	int	shifted_up;

	midpoint = find_section_midpoint(a, section->len);
	to_push = count_nums_to_push(a, midpoint);
	section->len -= to_push;
	shifted_up = pushback_to_b(to_push, midpoint, a, b);
	if (section->len <= 3)
		sort_while_shifting_down(a, b, shifted_up);
	else
	{
		while (shifted_up--)
			rra(a);
	}
	return (to_push);
}

int	pushback_to_b(int to_push, int mid, t_stack *a, t_stack *b)
{
	int		shifted_up;

	shifted_up = 0;
	while (to_push)
	{
		if (a->top->id <= mid)
		{
			pb(a, b);
			to_push--;
		}
		else
		{
			ra(a);
			shifted_up++;
		}
	}
	return (shifted_up);
}

/**
 * After repeatedly dividing a section in A and it is sorted, remove it 
 * from the list without affecting the other sections that are after it.
 */

void	remove_current_section_a(t_sections *sections, t_section *current)
{
	if (sections->tail == current)
		sections->tail = current->prev;
	current->next->prev = current->prev;
	current->prev->next = current->next;
	free(current);
}
