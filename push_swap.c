/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/22 22:59:10 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_arr		int_array;

	parse_arguments(argc, ++argv, &int_array);
	init_stacks(&stacks, &int_array);
	sort(&stacks, int_array.size);
	free_stacks(&stacks);
}

void	sort(t_stacks *stacks, int elements)
{
	t_sections	sections;

	if (stacks_are_sorted(stacks->a, stacks->b))
		return ;
	sections = (t_sections){NULL, NULL};
	add_unsorted_section('A', elements, &sections);
	sort_a(stacks, &sections);
	sort_b(stacks, &sections);
}

void	sort_a(t_stacks *stacks, t_sections *sections)
{
	t_section	*unsorted;
	static int	first_midpoint;
	static bool	first_call = true;

	unsorted = sections->head;
	if (first_call && unsorted->len > 5)
	{
		check_first_half(stacks, sections, &first_midpoint);
		first_call = !first_call;
	}
	if (unsorted->len > 5)
	{
		half_a_to_b(stacks, sections, first_midpoint);
		sort_a(stacks, sections);
	}
	else if (unsorted->len <= 5)
	{
		if (unsorted->next && has_remaining_first(stacks->a, first_midpoint))
			clear_remaining(stacks, sections, first_midpoint);
		solve_a(stacks, unsorted->len);
		remove_sorted_a(sections);
		return ;
	}
}

void	sort_b(t_stacks *stacks, t_sections *sections)
{
	t_stack		*a;
	t_stack		*b;
	t_section	*current_section;

	a = stacks->a;
	b = stacks->b;
	clear_sorted_sections(sections, stacks);
	current_section = sections->tail;
	if (NULL == current_section)
		return ;
	if (current_section->len > 3)
		divide_section(stacks, sections);
	else if (current_section->len <= 3)
	{
		if (current_section->in == 'A')
			sort_section_a(a, b, current_section->len);
		else if (current_section->in == 'B')
			sort_section_b(a, b, current_section->len);
		remove_last_section(sections);
	}
	sort_b(stacks, sections);
}
