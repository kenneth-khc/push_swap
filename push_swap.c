/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:59:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/10 21:14:38 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*list_of_integers;
	int		size;
	t_stack	a;
	t_stack	b;

	list_of_integers = NULL;
	size = 0;
	list_of_integers = parse_arguments(argc, ++argv, &size);
	init_stacks(list_of_integers, size, &a, &b);

// testing
	fill_stack_b_for_test(&b);
	peek_entire_stack(a, b);
	execute_instructions_for_test(&a, &b);
	peek_entire_stack(a, b);
// end test
}

void	peek_entire_stack(t_stack stack_a, t_stack stack_b)
{
	while (stack_a.top != NULL)
	{
		printf("Stack A: %d\n", stack_a.top->data);
		stack_a.top = stack_a.top->next;
	}
	printf("\n");
	while (stack_b.top != NULL)
	{
		printf("Stack B: %d\n", stack_b.top->data);
		stack_b.top = stack_b.top->next;
	}
	printf("\n");
}

void	fill_stack_b_for_test(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = malloc(sizeof(t_node));
	second = malloc(sizeof(t_node));
	third = malloc(sizeof(t_node));
	first->data = 30;
	first->next = second;
	second->data = 20;
	second->next = third;
	third->data = 10;
	third->next = NULL;

	stack_b->top = first;
}

void	execute_instructions_for_test(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
	// sa(a);
	// sb(b);
	// ss(a, b);
	// pa(a, b);
	// pb(a, b);
	// ra(a);
	// rb(b);
	// rra(a);
	// rrb(b);
	// rrr(a, b);
}