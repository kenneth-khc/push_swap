/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:26:31 by kecheong          #+#    #+#             */
/*   Updated: 2023/10/31 23:02:38 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	stack_is_empty(t_stack *stack)
{
	if (stack->top)
		return (false);
	return (true);
}

void	free_instruction_list(t_instruction *head)
{
	t_instruction	*prev;

	prev = NULL;
	while (head)
	{
		prev = head;
		head = head->next;
		free(prev);
	}
}
