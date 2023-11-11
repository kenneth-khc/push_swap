/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/11/10 22:52:14 by kecheong         ###   ########.fr       */
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
	if (stacks_are_not_sorted(&a, &b))
		quicksort(&a, &b, int_array->size);
	free_stacks(&a, &b);
	free(int_array); //
}

void	quicksort(t_stack *a, t_stack *b, int arr_size)
{
	t_section_list	sections;

	sections.head = NULL;
	sections.tail = NULL;
	init_section(a, 'A', arr_size, &sections);
	exit(0);
	sort_a(a, b, &sections);
	sort_b(a, b, &sections);
}

void	sort_a(t_stack *a, t_stack *b, t_section_list *sections)
{
	int	pushed;
	int	a_len;
	static int	call;
	static int first_midpoint;
	t_section	*current_section;

	a_len = stack_len(a);
	current_section = sections->tail;
	if (first_call(&call) && current_section->len > 5)
	{
		first_midpoint = find_midpoint(a);
		add_section(current_section->len / 2, sections, 'B');
	}
	if (a_len > 5)
	{
		pushed = push_half_to_b(a, b, sections, first_midpoint);
		(void)pushed;
		sort_a(a, b, sections);
	}
	else if (a_len <= 5)
	{
		if (elements_are_ascending(a))
			return ;
		if (a_len == 5)
			sort_five(a, b);
		else if (a_len == 4)
			sort_four(a, b);
		else if (a_len == 3)
			sort_three(a, b);
		else if (a_len == 2)
			if (a->top->id > a->top->next->id)
				optimized_swap('A', a, b);
		return ;
	}
}

void	sort_b(t_stack *a, t_stack *b, t_section_list *sections)
{
	t_section	*current_section;

	update_sections(sections, a, b);
	current_section = sections->tail;
	// print_section(current_section, a, b);
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

