/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:36:48 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Copies from src to dst and null terminates it
 * Returns the length of the string it tried to create
 * Behaviour is undefined if src is empty/NULL and if src and dst overlap
**/

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_strlen;

	src_strlen = ft_strlen(src);
	if (dstsize == 0)
		return (src_strlen);
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (src_strlen);
}
