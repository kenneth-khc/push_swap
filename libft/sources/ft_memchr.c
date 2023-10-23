/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:40:24 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Memchr locates the first occurrence of c in string s within n bytes
 * It does not expect the string to be null terminated, unlike strchr
 * It returns a pointer to the byte located, or NULL if it is not found
 * Casting s and c to unsigned char is necessary to ensure that the comparison
 * is done with unsigned char values 
**/

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *) ptr);
		ptr++;
	}
	return (NULL);
}
