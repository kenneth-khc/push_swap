/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:45:33 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/** 
 * Deletes all nodes after the node pointed to by lst
 * Use current to traverse the list
 * Use previous to keep track of the previous node
 * Set previous to current, then move current to the next node
 * Delete the previous node
 * Repeat until current is 0 
**/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*previous;

	if (!lst || !del)
		return ;
	current = *lst;
	previous = NULL;
	while (current)
	{
		previous = current;
		current = current->next;
		del(previous->content);
		free(previous);
	}
	*lst = NULL;
}
