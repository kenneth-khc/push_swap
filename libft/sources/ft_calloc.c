/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:45:37 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:33 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Dynamically allocates memory and initializes all its bytes to 0
 * Count is the number of elements to allocate, size is the size of each element
 * Returns a pointer to the allocated memory
 * Returns null if allocation fails 
**/

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	bytes;

	if ((int) count < 0 && (int) size < 0)
		return (NULL);
	bytes = count * size;
	if (bytes > UINT_MAX)
		return (NULL);
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}
