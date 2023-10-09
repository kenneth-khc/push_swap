/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpong_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:50:23 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/09 10:49:36 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stack *stack_a, t_stack *stack_b, t_section_list *list)
{
	int	mid;
	int	to_push;

	static int call;
	// if (stack_len(stack_b) <= 3)
	// {
	// 	reverse_sort_three_elements(stack_a, stack_b);
	// 	return ;
	// }
	printf("SORT_B CALL %d: SECTION LEN: %d\n", ++call, list->tail->len);
	fflush(stdout);
	// if (call == 5)
	// 	return ;
	if (list->tail == NULL)
		return ;
	if (list->tail->len <= 3)
	{
		printf("Base case triggered on call %d\n", call);
		printf("Section deleted on call %d: %d\n", call, list->tail->len);
		fflush(stdout);
		sort_section(stack_a, stack_b, list->tail->len);
		delete_section(list);
		// sort_b(stack_a, stack_b, list);
		// return ;
	}
	mid = find_mid_in_section(stack_b, list->tail->len);
	printf("Midpoint of sort_b call %d: %d\n", call, mid);
	to_push = find_number_to_push_b(mid, stack_b, list->tail->len);
	printf("Section len in sort_b call %d: %d\n", call, list->tail->len);
	printf("Numbers to push to stack A in call %d: %d\n", call, to_push);
	fflush(stdout);
	list->tail->len -= to_push;
	add_section(to_push, list);
	printf("Call %d, section added: %d, previous tail new value: %d\n", call, list->tail->len, list->tail->prev->len);
	fflush(stdout);
	peek_entire_stack(*stack_a, *stack_b);
	push_to_a(to_push, mid, stack_a, stack_b);
	peek_entire_stack(*stack_a, *stack_b);
	// if (call == 2)
	// 	exit(0);
	// sort_a(stack_a, stack_b, list->tail->len, list);
	fix_a(stack_a, stack_b, list);
	// delete_section(list);
	sort_b(stack_a, stack_b, list);
}

void	sort_section(t_stack *stack_a, t_stack *stack_b, int section_len)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	// if (!stack_b->top || !stack_b->top->next || !stack_b->top->next->next
	// 	|| section_is_sorted(stack_b->top, 3))
	// 	return ;
	if (section_len == 1)
	{
		pa(stack_a, stack_b);
		return ;
	}
	if (section_len == 2)
	{
		printf("pushed 2\n");
		printf("LOOK HERE: %d %d\n", stack_b->top->simplified, stack_b->top->next->simplified);
		fflush(stdout);
		if (stack_b->top->simplified == stack_a->top->simplified - 1)
		{
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			sb(stack_a, stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		return ;
	}
	if (section_len == 3)
	{
		while (section_len--)
		{
			if (stack_b->top->simplified == stack_a->top->simplified - 1)
				pa(stack_a, stack_b);
			else if (stack_b->top->next->simplified == stack_a->top->simplified - 1)
			{
				sb(stack_a, stack_b);
				pa(stack_a, stack_b);
			}
			else
			{
				rb(stack_a, stack_b);
				sb(stack_a, stack_b);
				pa(stack_a, stack_b);
				rrb(stack_a, stack_b);
			}
		}
	}
	// if (stack_b->top->simplified < stack_b->top->next->simplified
	// 	&& !stack_b->top->next->next)
	// {
	// 	sb(stack_b);
	// 	pa(stack_a, stack_b);
	// 	return ;
	// }
	first = stack_b->top;
	second = first->next;
	third = second->next;
}

int	find_number_to_push_b(int mid, t_stack *stack, int section_len)
{
	int		to_push;
	t_node	*current;
	int		i;

	i = 0;
	to_push = 0;
	current = stack->top;
	while (i < section_len)
	{
		if (current->simplified >= mid)
			to_push++;
		current = current->next;
		i++;
	}
	return (to_push);
}

void	push_to_a(int to_push, int mid, t_stack *stack_a, t_stack *stack_b)
{
	int	rotated;
	static int tobreak;

	rotated = 0;
	while (to_push)
	{
		if (stack_b->top->simplified >= mid)
		{
			printf("LEFT TO PUSH: %d\n", to_push);
			printf("PUSHING: %d\n", stack_b->top->simplified);
			fflush(stdout);
			pa(stack_a, stack_b);
			if (stack_a->top->simplified > stack_a->top->next->simplified)
				sa(stack_a, stack_b);
			if (--to_push == 0)
				break ;
		}
		rb(stack_a, stack_b);
		rotated++;
		if (tobreak++ == 100)
			return ;
	}
	while (--rotated)
	{
		rrb(stack_a, stack_b);
		if (tobreak++ == 100)
			return ;
	}
}

bool	elements_left_to_push(int mid, t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->simplified >= mid)
			return (true);
		current = current->next;
	}
	return (false);
}
