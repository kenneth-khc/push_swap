/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/19 22:53:59 by kecheong         ###   ########.fr       */
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
	free(int_array); //
}

void	quicksort(t_stack *a, t_stack *b, int arr_size)
{
	t_section_list	sections;

	if (stacks_are_sorted(a, b))
		return ;
	sections = (t_section_list){NULL, NULL};
	init_section('A', arr_size, &sections);
	sort_a(a, b, &sections);
	sort_b(a, b, &sections);
}

void	sort_a(t_stack *a, t_stack *b, t_section_list *sections)
{
	int			pushed;
	// int			len;
	static int	first_midpoint;
	static bool	first_call = true;
	t_section	*unsorted_a;

	// len = stack_len(a);
	unsorted_a = sections->head;
	if (first_call && unsorted_a->len > 5)
	{
		first_midpoint = find_midpoint(a);
		add_section(find_num_to_add(a, first_midpoint), sections, 'B');
		if (unsorted_a->len - unsorted_a->next->len <= 5)
		{
			push_first_section(a, b, unsorted_a->next->len, first_midpoint);
			sort_a(a, b, sections);
			return ;
		}
		first_call = false;
	}
	if (unsorted_a->len > 5)
	{
		pushed = push_half_to_b(a, b, sections, first_midpoint);
		(void)pushed;
		sort_a(a, b, sections);
	}
	else if (unsorted_a->len <= 5)
	{
		solve_a(a, b, unsorted_a->len);
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
		if (last->len == 0 || section_is_ascending(a, last->len))
			remove_section(sections);
	}
	else if (last->in == 'B')
	{
		if (last->len == 0)
			remove_section(sections);
		else if (section_is_descending(b, last->len))
		{
			push_sorted_section(a, b, last->len);
			remove_section(sections);
		}
	}
}
