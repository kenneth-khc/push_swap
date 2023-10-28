/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/28 18:52:16 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*list_of_integers;
	int		size;
	t_stack	a;
	t_stack	b;

	size = 0;
	list_of_integers = parse_arguments(argc, ++argv, &size);
	init_stacks(&a, &b, list_of_integers, size);
	if (stacks_are_not_sorted(&a, &b))
		quicksort(&a, &b, size);
	free_stack(&a);

// printf("--------------------------------- END RESULT --------------------------------\n");
// printf("SIZE: %d\n", size);
// peek_entire_stack(a, b);
}

void	quicksort(t_stack *a, t_stack *b, int size)
{
	t_section_list	sections;

	sections.head = NULL;
	sections.tail = NULL;

	sort_a(a, b, size, &sections);

	t_section *current;
	current = sections.head;
	while (current)
	{
		// printf("SECTION LIST BEFORE SORT B: %d\n", current->len);
		current = current->next;
	}

	sort_b(a, b, &sections);
}

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
		if (elements_are_ascending(a))
			return ;
		if (len == 5)
			sort_five(a, b);
		else if (len == 4)
			sort_four(a, b);
		else if (len == 3)
			sort_three(a, b);
		else if (len == 2)
			if (a->top->simplified > a->top->next->simplified)
				sa(a, b);
		return ;
	}
}

void	sort_b(t_stack *a, t_stack *b, t_section_list *sections)
{
	t_section	*current_section;

	current_section = sections->tail;
	if (current_section == NULL)
		return ;
	if (current_section->len > 3)
		divide_section(a, b, sections);
	else if (current_section->len <= 3)
	{
		sort_current_section(a, b, current_section);
		remove_section(sections);
	}
	sort_b(a, b, sections);
}
