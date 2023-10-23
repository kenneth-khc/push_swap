/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:21:10 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Counts the number of nodes in the linked list
 * Set a pointer to keep track of the current node
 * While the current node is not NULL, move to the next node
 * Increment the counter 
**/

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
