/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:18:11 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Locates the first occurence of needle in a haystack within len
 * Characters after a '\0' are not searched
 * If needle is an empty string, haystack is returned
 * If needle is not found in haystack, NULL is returned 
**/

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*needle == '\0')
		return ((char *)(haystack));
	if ((!haystack && !needle) || len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (*(haystack + i) && i < len)
	{
		while (*(haystack + i + j) == *(needle + j) && i + j < len)
		{
			j++;
			if (*(needle + j) == '\0')
				return ((char *) haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
