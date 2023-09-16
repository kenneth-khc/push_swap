/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpong_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:50:23 by kecheong          #+#    #+#             */
/*   Updated: 2023/09/16 20:21:49 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stack *stack_a, t_stack *stack_b, t_section_list *list)
{
	int	mid;
	int	*temp_array;
	int	to_push;

	static int i;
	printf("CALL %d: SECTION LEN: %d\n", i++, list->tail->len);
	if (i == 4)
		return ;
	if (list->tail->len <= 3)
	{
		reverse_sort(stack_a, stack_b, list->tail->len);
		delete_section(list);
		printf("SECTION LEN: %d\n", list->tail->len);
	}
	if (!list->head)
		return ;
	temp_array = init_temp_array(stack_b);
	mid = find_mid(temp_array, list->tail->len);
	printf("MIDPOINT: %d\n", mid);
	free(temp_array);
	to_push = find_number_to_push_b(mid, stack_b, list->tail->len);
	printf("SECTION LEN: %d\n", list->tail->len);
	printf("TO PUSH TO A: %d\n", to_push);
	list->tail->len -= to_push;
	add_section(to_push, list);
	peek_entire_stack(*stack_a, *stack_b);
	push_to_a(to_push, mid, stack_a, stack_b);
	delete_section(list);
	sort_b(stack_a, stack_b, list);
}

void	reverse_sort(t_stack *stack_a, t_stack *stack_b, int section_len)
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
		// delete_section(list);
		return ;
	}
	if (section_len == 2)
	{
		printf("pushed 2\n");
		if (stack_b->top == stack_a->top - 1)
		{
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			sb(stack_b);
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
				sb(stack_b);
				pa(stack_a, stack_b);
			}
			else
			{
				rb(stack_b);
				sb(stack_b);
				pa(stack_a, stack_b);
				rrb(stack_b);
			}
		}
	}
	if (stack_b->top->simplified < stack_b->top->next->simplified
		&& !stack_b->top->next->next)
	{
		sb(stack_b);
		pa(stack_a, stack_b);
		return ;
	}
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
		if (current->simplified <= mid)
			to_push++;
		current = current->next;
		i++;
	}
	return (to_push);
}
