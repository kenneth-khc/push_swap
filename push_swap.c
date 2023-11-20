/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/20 21:33:48 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_int_array	*int_array;

	int_array = parse_arguments(argc, ++argv);
	init_stacks(&a, &b, int_array);
	quicksort(&a, &b, int_array->size);
	free_stacks(&a, &b);
}

void	quicksort(t_stack *a, t_stack *b, int elements)
{
	t_section_list	sections;

	if (stacks_are_sorted(a, b))
		return ;
	sections = (t_section_list){NULL, NULL};
	init_section('A', elements, &sections);
	sort_a(a, b, &sections);
	sort_b(a, b, &sections);
}

void	sort_a(t_stack *a, t_stack *b, t_section_list *sections)
{
	int			pushed;
	static int	first_midpoint;
	static bool	first_call = true;
	t_section	*unsorted;

	unsorted = sections->head;
	if (first_call && unsorted->len > 5)
	{
		determine_first_section(sections, &first_midpoint, a, b);
		first_call = false;
	}
	if (unsorted->len > 5)
	{
		pushed = push_half_to_b(a, b, sections, first_midpoint);
		(void)pushed;
		sort_a(a, b, sections);
	}
	else if (unsorted->len <= 5)
	{
		if (unsorted->next && has_remaining(a, first_midpoint))
			clear_remaining(a, b, sections, first_midpoint);
		solve_a(a, b, unsorted->len);
		remove_sorted_a(sections);
		return ;
	}
}

void	sort_b(t_stack *a, t_stack *b, t_section_list *sections)
{
	t_section	*current_section;

	update_sections(sections, a, b);
	current_section = sections->tail;
	if (current_section == NULL)
		return ;
	if (current_section->len > 3)
		divide_section(a, b, sections);
	else if (current_section->len <= 3)
	{
		if (current_section->in == 'B')
			sort_section_b(a, b, current_section->len);
		else if (current_section->in == 'A')
			sort_section_a(a, b, current_section->len);
		remove_section(sections);
	}
	sort_b(a, b, sections);
}

void	update_sections(t_section_list *sections, t_stack *a, t_stack *b)
{
	t_section	*last;

	last = sections->tail;
	if (!last)
		return ;
	if (last->in == 'A')
	{
		// if (last->len == 0 || section_is_ascending(a, last->len))
		if (section_is_ascending(a, last->len))
			remove_section(sections);
	}
	else if (last->in == 'B')
	{
		// if (last->len == 0)
		// 	remove_section(sections);
		if (section_is_descending(b, last->len))
		{
			push_sorted_section(a, b, last->len);
			remove_section(sections);
		}
	}
}
