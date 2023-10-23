/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:47:22 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterates through the list lst and applies the function f to each node
 * Stores the modified nodes in a new list
 * Returns the new list 
**/

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_node;

	new_list = NULL;
	current = lst;
	new_node = NULL;
	if (!lst)
		return (NULL);
	while (current)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		new_node->content = f(current->content);
		new_node->next = NULL;
		ft_lstadd_back(&new_list, new_node);
		current = current->next;
	}
	return (new_list);
}
