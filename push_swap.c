/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/25 19:28:53 by kecheong         ###   ########.fr       */
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
	if (!stacks_are_sorted(&a, &b))
		quicksort(&a, &b, size);
	else
		return (0);

// printf("--------------------------------- END RESULT --------------------------------\n");
// printf("SIZE: %d\n", size);
// peek_entire_stack(a, b);
}

void	quicksort(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_section_list	sections;

	sections.head = NULL;
	sections.tail = NULL;

	sort_a(stack_a, stack_b, size, &sections);

	t_section *current;
	current = sections.head;
	while (current)
	{
		// printf("SECTION LIST BEFORE SORT B: %d\n", current->len);
		current = current->next;
	}

	sort_b(stack_a, stack_b, &sections);
}
