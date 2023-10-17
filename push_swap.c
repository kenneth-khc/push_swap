/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/10 16:08:47 by kecheong         ###   ########.fr       */
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

	pingpong(&a, &b, size);
	
printf("--------------------------------- END RESULT --------------------------------\n");
peek_entire_stack(a, b);
}

void	pingpong(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_section_list	sections;

	if (stacks_are_sorted(stack_a, stack_b))
		return ;
	printf("SIZE: %d\n", size);
	sections.head = NULL;
	sections.tail = NULL;


	sort_a(stack_a, stack_b, size, &sections);

	t_section *current;
	current = sections.head;
	while (current)
	{
		printf("SECTION LIST BEFORE SORT B: %d\n", current->len);
		current = current->next;
	}

	sort_b(stack_a, stack_b, &sections);
}