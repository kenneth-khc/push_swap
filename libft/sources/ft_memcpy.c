/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:32:03 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/09 11:59:43 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Copies n bytes from memory area src to memory area dst
 * If dst and src overlap, behavior is undefined
 * It returns a pointer to dst 
**/

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (char *) dst;
	src_ptr = (char *) src;
	while (n--)
		dst_ptr[n] = src_ptr[n];
	return (dst);
}
