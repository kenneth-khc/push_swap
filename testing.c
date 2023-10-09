/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:27:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/09 19:48:59 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	peek_entire_stack(t_stack stack_a, t_stack stack_b)
{
	printf("Stack A: ");
	while (stack_a.top)
	{
		printf("%d ", stack_a.top->simplified);
		stack_a.top = stack_a.top->next;
	}
	printf("\nStack B: ");
	while (stack_b.top)
	{
		printf("%d ", stack_b.top->simplified);
		stack_b.top = stack_b.top->next;
	}
	printf("\n");
	fflush(stdout);
}

void	peek_section_list(t_section_list sections)
{
	t_section *current;

	current = sections.head;
	printf("Sections: ");
	while (current)
	{
		printf("%d ", current->len);
		current = current->next;
	}
	printf("\n");
	fflush(stdout);

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